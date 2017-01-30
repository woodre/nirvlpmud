/* **********************************************
*                                               *
*               Jareel 1/8/2004                 *
* /players/jareel/armor/orlanth/wind_sandles.c  *
*                                               *
* Object gives player extra attack if worn with *
*              the complete set                 *
* Armor specials hit 22% of the time in order   *
* to get the specials a player sacrifices 6     *
* points of armor, cause he needs all 3 pieces  *
* worn for the specials to work.                *
********************************************** */

#include "/players/jareel/define.h"
inherit "/obj/armor.c";
#define ATT USER->query_attack()
#define USER environment(this_object())

/* Global Variables */
string *Armor_pieces;
status Ghetto; /* Ghetto fix, based on speed bracers */
object Owner;

void
init()
{
  ::init();
  add_action("ghetto_it","ghetto_it");

  if (environment(this_object()) && this_player() == environment(this_object())) {
    Owner = this_player();
    call_out("do_shit", 1 + random(10));
  }
}
  
void
reset(status arg)
{

  ::reset(arg);

  if (arg)
    return;

  set_name("wind sandals");
  set_ac(0);
  set_value(4200);
  set_weight(1);
  set_type("boots");
  set_short(HIB+"Sandals"+NORM+BLU+" of the rushing "+HIB+"Storm"+NORM);
  set_long(
    "                      "+HIG+"Set of the Wind"+NORM+"\n"+
    "A swirling blue and white set of sandals.  The sandals slide over\n"+
    "your feet providing little protection.  The sandals feel like they\n"+
    "would enable you to move very quickly.\n");

  /* Put the id's for special armors required here */
  Armor_pieces = ({ "wind_amulet", "wind_helm", "wind_sandles" });
     }

status id(string arg) { return ( ::id(arg) || arg == "wind_sandles" || arg == "sandals" || arg == "storm sandals" || arg == "sandals of the rushing storm"); }

status check_full_set() {
  int i;

  i = sizeof(Armor_pieces);

  while(i--) {
    object t;
    t = present(Armor_pieces[i], USER);

    if (!t || !((status)t->query_worn()))
      return 0;
  }
  return 1;
}

string short() {

  if (check_full_set())
    return (HIB+"Sandals "+NORM+BLU+"of the rushing "+NORM+HIB+"Storm"+NORM+BOLD+" ("+NORM+HIG+"Set of the Wind"+NORM+BOLD+")"+NORM+" (worn)"+NORM);

  if ((status)this_object()->query_worn())
    return(HIB+"Sandals "+NORM+BLU+"of the rushing "+NORM+HIB+"Storm"+NORM+NORM+" (worn)");

  return HIB+"Sandals "+NORM+BLU+"of the rushing "+HIB+"Storm"+NORM+NORM;
}

void do_shit() {
  object hh;

    if(!environment(this_object())) return;

    while(remove_call_out("do_shit") != -1);
    call_out("do_shit",1+random(10));

    hh = environment(environment(this_object()));

    if (!check_full_set()) return;

  if (!((object)Owner->query_attack()))
     return;

    if(!hh) return;

    say("SAY: double attack\n");
  tell_object(Owner, "TO: double attack\n");

   Ghetto = 1;
    command("ghetto_it", Owner);
tell_object(find_player("jareel"), "OK MOTHERFUCKER, Owner is: "+(string)Owner->query_real_name()+"\n");
}

do_special(owner) {
  int i;
  object me;

  me = environment(this_object());
  if (random(1000) > 222) /* It only hits 22% of the time */
    return 0; 
  i = sizeof(Armor_pieces);
  while(i--) {
    object t;
    t = present(Armor_pieces[i], USER);
    if (!t || !((status)t->query_worn()))
      return 0;
}

  /* Using a fix for this shit based on the speed bracers. */
  Ghetto = 1;
  command("ghetto_it", me);
  return 100;
}

int ghetto_it() {
  object wep, att, me;

  if (!Ghetto)
    return 1;

  Ghetto = 0;

tell_object(Owner, "\n\n\nYEAH MOTHERFUCKER WE'RE IN THE GHETTO NOW!\nHUG SOME NUTSACK BABY!\n\n\n");
write("WRITE TEST\n");
say("SAY TEST\n");
  me = this_player();
  att = (object)me->query_attack();
  wep = (object)me->query_weapon();

  if (!att)
    return 1;

/*
*/

  me->toggle_already_fight(1);
  me->attack();

  if (wep)
    wep->hit(att);

tell_room(environment(me), 
 ""+BOLD+" <"+BLU+"<>"+NORM+BOLD+">"+BLU+" Rushing wind surounds "+me->query_name()+"'s body "+NORM+BOLD+" <"+BLU+"<>"+NORM+BOLD+">\n"+NORM);
  return 1;
}
