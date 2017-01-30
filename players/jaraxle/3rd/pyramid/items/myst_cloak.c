/* **************************************************************************
 * File:           /players/jaraxle/3rd/pyramid/items/myst_cloak.c          *
 * Function:       Cloak that grants invisibility and specials when worn    *
 * Author:         Jaraxle                                                  *
 * Copyright:      Copyright (c) 2004 Jaraxle.  All rights reserved.        *
 * Source:                                                                  *
 * Notes:          - Recoded almost totally by Earwax on 5/25/04            *
 * Change History: - 5/25/04 Earwax                                         *
 *                   Added Headers, changed how it grants invisibility and  *
 *                   fixed bugs with it being worn and granting invisbility *
 *                   when it wasn't worn or even in inventory of the player *
 *                   Recoded to pretty much drop it to a few functions, too *
 *                   many functions to do what are essentially very simple  *
 *                   actions.                                               *
 *                   Added reply ability                                    *
 *  04/16/13 Dragnar                                                        *
 *                   Added Mage guild bonus.  Fixed a bug with the message  *
 *                   to the user, and also cut down on spam messages.       *
 *                   Fixed issue when sps < 0.                              *
 * *************************************************************************/

inherit "/obj/armor.c";
#include "/players/jaraxle/define.h"

#define GUILDID "mageobj"
#define BONUS_TYPE "illusion"
#define BONUS_AMOUNT 2

/* Global Variables */
int invis_flag, saveflag;
string ReplyToPlayer;

/* Prototype Declarations */
void invis_me(object ob);
void vis_me(object ob);

/* **************************************************************************
 * Function:    reset 
 * Description: Called when item is created, and when it's reset 
 * Arguments:   status arg - 0 for creation, 1 for reset
 * Return:      void 
 * *************************************************************************/
void reset(status arg) { /* Changed int to status :) */
   if(arg) return;
   ::reset();
   set_name("misty cloak");
   set_alias("cloak");
   set_short(HIW+"Misty Cloak"+NORM);
   set_long(
      "A strange swirling mass of mist and form.  The shadows of mist shape\n"+
      "into a cloak which feels cool to the touch.  A mist of water feigns from\n"+
      "about the mist, refreshing your body and mind.\n");
   set_ac(1);
  /*AC 1 because of special powers. -Bp */
   set_type("cloak");
   set_weight(0);
   set_value(10000+random(10000));
   ReplyToPlayer = 0;
}
/* **************************************************************************
 * Function:    init
 * Description: Actions to occur when the cloak enters environment of a living
 * Arguments:   none
 * Return:      void 
 * *************************************************************************/
void
init(){
   ::init();
   add_action("wear","wear");
   add_action("remove","remove");
   add_action("cmd_tell","tell");
   add_action("cmd_tell","reply");
}
/* **************************************************************************
 * Function:     do_special
 * Description:  armor special 1/6 chance of return 2+random(9)
 * Arguments:    string
 * Return:       int - 0 for failure, 1 for success
 * *************************************************************************/
do_special(owner){
   if(!random(6)){
      tell_object(owner,  HIC+"\tThe air around you shakes as the cloak protects you.\n"+NORM+NORM);
      if(this_player() && this_player()!=owner)
         write("The air around "+owner->query_name()+" seems to distort.\n");
      return 2+random(9);
   }
}

/* **************************************************************************
 * Function:     query_guild_bonus
 * Description:  Mage guild bonus
 * Arguments:    void
 * Return:       BONUS_AMOUNT
 * *************************************************************************/
query_guild_bonus(){ return BONUS_AMOUNT; }

/* **************************************************************************
 * Function:     add_guild_bonus
 * Description:  Mage guild bonus
 * Arguments:    void
 * Return:       void
 * *************************************************************************/
add_guild_bonus()
{
  if(present(GUILDID, this_player()))
	  present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE, BONUS_AMOUNT);
}

/* **************************************************************************
 * Function:     remove_guild_bonus
 * Description:  Mage guild bonus
 * Arguments:    void
 * Return:       void
 * *************************************************************************/
remove_guild_bonus()
{
  if(present(GUILDID, this_player()))
	  present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE, -BONUS_AMOUNT);
}
/* **************************************************************************
 * Function:     wear_misty_cloak, remove_misty_cloak
 * Description:  Special wear function - starts call-out for invisibility
 * Arguments:    arg - what the user typed as an arg to 'wear' command
 * Return:       status - 0 for failure, 1 for success
 * *************************************************************************/
/*
int
wear(string arg)
{
  object ob;
  int junk;
  
  if (!((status)this_object()->query_worn()) && ::wear(arg) && (status)this_object()->query_worn())
  {
    write("You wrap the cloak around your body.\n\t"+HIW+"~ ~ "+HIC+"The room begins to waver around you"+HIW+" ~ ~\n"+NORM+NORM);
    invis_me(this_player());
    return 1;
  }

  UHHHH.. wtf?
  if (query_verb() == "ready")
    return 1;


  if (sscanf(arg, "%s %d", arg, junk) == 2)
  {
    if (id(arg))
      return (int)present(arg + " " + junk, this_player())->wear(arg);
    else
      return 0;
  }
            
}
*/

int wear(string arg)
{
  status wFlag;
  status x;
  wFlag = worn;
  x = (int)::wear(arg);
  if(!wFlag && worn)
  {
    write("You wrap the cloak around your body.\n\t"+HIW+"~ ~ "+HIC+
       "The room begins to waver around you"+HIW+" ~ ~\n"+NORM);
    invis_me(this_player());
  }
  return x;
}
status
remove(string arg)
{
  status wFlag, x;
  wFlag = worn;
  x = (int)::remove(arg);
  if(wFlag && !worn)
  {
    write("You remove the misty cloak.\n");
    vis_me(this_player());
  }
  return x;

}
 
/* **************************************************************************
 * Function:     invis_me, vis_me
 * Description:  Make the wearer invisible or visible
 * Arguments:    Player object - just a safety, really
 * Return:       void
 * *************************************************************************/
void
invis_me(object ob)
{
  string msg;
  
  if (!ob || !((status)this_object()->query_worn()))
    return;

  if (environment() && environment(this_object()) == ob)
  {
    if ((int)ob->query_invis() < 1)
      ob->set_invs_sp();

    call_out("invis_me", 10, ob);
  }
  else
    return;

  if( !random(10) ) {
    switch(random(3))
    {
      case 0: msg = "The cloak wavers for a moment.\n";
        break;
      case 1: msg = "The room seems to quickly spin.\n";
        break;
      case 2: msg = "You feel a cold chill from inside the cloak.\n";
        break;
    }

    msg = HIC+msg+NORM+NORM;
    tell_object(ob, msg);
  }
  
   /* add an sp cost -Bp */
  if(random(100)<40) 
  {
    ob->add_spell_point(-3);

    if((int)ob->query_spell_point() < 0)
    {
      /* Make invis turn off since they are out of sps */
      vis_me(ob);
    }
  }
}

void
vis_me(object ob)
{
  write("The cloak flickers slowly.\n");
 if(ob)
  {
  ob->visible();
  ob->unset_invs_sp();
  }
  if(environment())
  tell_object(environment(), ""+HIC+"~ ~ "+HIW+"The room wavers in front of you"+HIC+" ~ ~\n"+NORM+NORM);
  while(remove_call_out("invis_me") != -1);
}
/* **************************************************************************
 * Function:     cmd_tell
 * Description:  Allow wearer to send tells while invis
 * Arguments:    string
 * Return:       int - 0 for failure, 1 for success
 * *************************************************************************/

cmd_tell(str) {
   object plyr;
   int X, CK;
   string myname, who, what, verb;  
   if(!str) { 
      write("Excuse me?\n"); 
      return 1; 
   }

   /*
    * Earwaxian addition :)
   */   
   verb = query_verb();

   if (verb == "reply")
   {
     if (ReplyToPlayer)
     {
       who = ReplyToPlayer;
       what = str;
     }
     else
     {
       notify_fail("Nobody to reply to.\n");
       return 0;
     }
   }
   /* attempt to type fewer letters */
   
   if(verb != "reply" && sscanf(str,"%s %s",who,what) < 2) 
      {
      write("Tell <who> <what>.\n"); 
      return 1; 
   }
   
   if(TP->query_sp() <= 1){
      write("You do not have the spell points to tell to "+capitalize(who)+".\n");
      return 1; }
   plyr = find_living(who);
   myname = capitalize(this_player()->query_real_name());
   if(!plyr) { write(capitalize(who)+" is not on now.\n");
      return 1; 
   }
   if (plyr->query_invis() > 19) {
      write("No player with that name.\n");
      return 1; }
   
if(in_editor(plyr)){
    write("That person is editing. Please try again later.\n"); return 1;
  if(TP->query_level() < 21 && plyr->query_tellblock()) {
    write("That person is blocking tells. Please try again later.\n");
    return 1; }
  if(query_idle(plyr) > 120)
tell_object(TP, plyr+" is idle at the moment. You may not get a response right away.\n");
    }
  if(!plyr->query_npc() && !interactive(plyr))
    tell_object(TP, capitalize(who)+" is disconnected.\n");
   tell_object_wblock(plyr,""+HIW+myname+" tells you"+NORM+": "+what+"\n");
   write(HIW+"You tell "+capitalize(who)+""+NORM+": "+what+"\n");
   plyr->add_tellhistory(HIW+myname+" told you: " + what + NORM);
    plyr->Replyer(TPN);
    ReplyToPlayer = who;
   TP->add_spell_point(-1);
   return 1;
}

/* **************************************************************************
 * Function:     give, drop
 * Description:  Ensure that the cloak uninvises
 * Arguments:    none
 * Return:       int - 0 for failure, 1 for success
 * *************************************************************************/
drop(){
  this_object()->remove("misty cloak");
  ::drop();
}
give(){
  this_object()->remove("misty cloak");
/*
  ::give();
*/
}

