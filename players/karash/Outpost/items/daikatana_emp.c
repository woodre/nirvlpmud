
inherit "obj/weapon.c";
#include <ansi.h>

/******************************************************************************
 * Program: daikatana_emp.c
 * Path: /players/karash/Outpost/items
 * Type: weapon
 * Created: July 2014 by Karash
 *
 * Purpose: John Romero the Criticized's weapon - empowered
 *			When John Romero the Criticized is called, his Daikatana becomes
 *			empowered, giving it new qualities
 *
 * History:
 *          
 ******************************************************************************/

 int charges;
 
 
 reset(arg) 
{
    ::reset(arg);
    if (arg) return;

	charges = 3;
	
    set_name("daikatana");
    SetMultipleIds( ({ "daikatana", "sword", "katana" }) );
    set_short(GRY+"Daikatana"+NORM+" ("+RED+"empowered"+NORM+")");
    set_long("A long, curved, single-edged sword that seems longer than a normal\n\
katana.  It currently has a fiery mist emanating from the blade as it\n\
resonates in the hand holding it.  It is not known how to empower the\n\
sword initially, but once it is empowered, some of its abilities have\n\
been learned through John Romero.  However, these secret incantations\n\
may benefit him more than anyone else and the secret to the awesome\n\
damage shield is still not public knowledge.  When empowered, the\n\
wielder of this sword knows how to '"+CYAN+"healme"+NORM+"' or '"+MAG+"call fanboy"+NORM+"'.\n");

    set_class(15);
    set_params("other|fire",15,0);
    set_weight(2);
    set_value(17500);
	set_save_flag(1);
    /* set_hit_func(this_object()); */
	
	
}

/****************************************************************************
 * This sword has 2 abilities the player can access if the sword is wielded.
 * However, the sword only has 3 charges and is non-saveable.
 *   1) "healme" - Heal spell will heal wielder, but can also be cast to heal
 *                 other living creatures using "healme <targetname>".
 *                 (transfer tox rules apply)
 *   2) "call fanboy" - Wielder can call a fan of John Romero from the ether.
 *                 However, Fanboy will do nothing to assist the player. In 
 *                 fact, if Fanboy is present when John Romero is attacked, 
 *                 nasty stuff can happen.
 *****************************************************************************/
 
init()
{  
::init();
  add_action("heal_me", "healme");
  add_action("call_fanboy", "call");
}

/*  Check to see if sword is wielded - DONE
 *  Check to see if target for heal is living and present
 *  Check to see if another fanboy is in room (only 1 per room) - DONE
 *  Set charges to 3 - once charges drop to 0, change name to (unpowered) - DONE
 *  Since sword is non-saveable, make it permanently sharpened - DONE
 */

/****************** 
 ** healme spell **
 ******************/
heal_me(str)
{
object healtarget;

if(!wielded)  /** what about offwield? **/
  {
  tell_object(this_player(), "You must wield the "+GRY+"Daikatana"+NORM+" to access that power.\n");
  return 1;
  }
  
/* Prevents the negative charges bug.  */
if (charges < 0)
  {
  charges = 0;
  }

if(charges == 0) 
  { 
  tell_object(this_player(), "Nothing happens.  The "+GRY+"Daikatana"+NORM+" is powered down.\n");
  return 1;
  } 

if(!str)
{

  /* Note: add_hit_point and add_spell_point DOES check for MAXHP and MAXSP to avoid overheal */
  this_player()->add_hit_point(95);
  this_player()->add_spell_point(95);
  tell_object(this_player(), "You feel rejuvenated.\n");
  charges--;
  if(charges == 0)
    {
    tell_object(this_player(), "\n"+GRY+"Daikatana"+NORM+" powers down.\n");
    set_short(GRY+"Daikatana"+NORM+" ("+CYAN+"unpowered"+NORM+")");
    }
return 1;
}

/** This gives the ability to heal other living targets  **/
/** Transfer Tox is applied when healing others          **/
if(str)
{
healtarget = present(str,environment(this_player()));
if(!healtarget || !living(healtarget))
  {
    tell_object(this_player(), "That is not a valid target.\n");
    return 1;
  }    
if(healtarget && living(healtarget))
  {
    healtarget->add_hit_point(95);
    healtarget->add_spell_point(95);
    tell_object(this_player(), "You have rejuvenated "+capitalize(str)+".\n");
    tell_object(healtarget, "You have been rejuvenated by "+this_player()->query_name()+" with the power of the "+GRY+"Daikatana"+NORM+".\n");
	charges--;
    if(charges == 0)
      {
      tell_object(this_player(), "\n"+GRY+"Daikatana"+NORM+" powers down.\n");
      set_short(GRY+"Daikatana"+NORM+" ("+CYAN+"unpowered"+NORM+")");
      }
  return 1;
  }
}	
return 1;
}

/*************************
 ** "call fanboy" spell **
 *************************/
call_fanboy(str)
{

if(!wielded)  /** what about offwield? **/
  {
  tell_object(this_player(), "You must wield the "+GRY+"Daikatana"+NORM+" to access that power.\n");
  return 1;
  }
  
/* Prevents the negative charges bug.  */
if (charges < 0)
  {
  charges = 0;
  }
  
if(charges == 0) 
  { 
  tell_object(this_player(), "Nothing happens.  The "+GRY+"Daikatana"+NORM+" is powered down.\n");
  return 1;
  } 

if(str == "fanboy")  
{
  if(present("fanboy",environment(this_player())))
  {
    tell_object(this_player(), "There is already enough fandom here.\n");
	return 1;
  }
  else
  {
    move_object(clone_object("/players/karash/Outpost/mobs/fanboy"), environment(this_player()));
    tell_room(environment(this_player()), "A fanboy has instantly appeared.\n"); 
    charges--;	
	if(charges == 0)
      {
      tell_object(this_player(), "\n"+GRY+"Daikatana"+NORM+" powers down.\n");
      set_short(GRY+"Daikatana"+NORM+" ("+CYAN+"unpowered"+NORM+")");
      }
    return 1;
  }
}
}

/** Code to show available charges on sword **/
void show_charges()
{
  int ch;

  if(charges == 1)
    ch = 1;

  write("There " + (ch ? "is" : "are") + " " +CYAN+ charges +
        " " + (ch ? "charge" : "charges") +NORM+ " remaining.\n");
}

/** To show available charges when player looks at sword **/
void long() {
  ::long();
  show_charges();
}

/** To keep sword permanently sharpened **/
query_wear() {
   int wear;
   wear = 0;
  return wear;
}

