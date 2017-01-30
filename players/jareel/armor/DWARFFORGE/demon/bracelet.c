/* Bracers of Speed */

#include "/players/jareel/define.h"
inherit "/obj/armor.c";
#define ATT USER->query_attack()
#define USER environment(this_object())
#define THUNDER HIY+"Sun Forged"+NORM 

/* Global Variables */
string *Armor_pieces;
status Ghetto; /* Ghetto fix, based on speed bracers */
object Owner;

void
init()
{
  ::init();
  add_action("ghetto_it","ghetto_it");
}
  
void
reset(status arg)
{

  if (arg)
    return;

  ::reset(arg);

  set_name("bracers");
  set_ac(0);
  set_value(27000); /* Set High so if you buy them in the shop they are expensive */
  set_weight(1);
  set_type("bracelet");
  set_light(1);
  set_short(HIK+"Demon Bracers"+NORM+" ["+THUNDER+"]");
  set_long(
    "Bracers Forged in the in Yelm's Sun fire, an ancient practice\n"+
    "that turns chaotic flesh into a protective substance.\n");
}

int do_special(object owner) {
  int i;
  object hh;
    i = random(15);
      if (i > 1) return 0;
    Ghetto = 1;
      command("ghetto_it", owner);
   return 1;
}

int ghetto_it() {
  object wep, att, me;
  if (!Ghetto)
    return 1;
  Ghetto = 0;
  me = this_player();
  att = (object)me->query_attack();
  wep = (object)me->query_weapon();
  if (!att)
    return 1;
  me->toggle_already_fight(1);
  me->attack();
  if (wep)
    wep->hit(att);
tell_room(environment(me), 
 ""+BOLD+me->query_name()+"'s body blurs with deadly speed\n"+NORM);
  return 1;
}