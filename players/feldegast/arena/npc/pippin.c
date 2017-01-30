#include "/players/feldegast/closed/ansi.h"
inherit "/obj/monster";
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Pippin");
  set_alt_name("pip");
  set_alias("pippin");
  set_short("Pippin");
  set_long(
"The unkempt dwarf before you wears a pot on his head, carries\n"+
"a frying pan in his right hand, and takes frequent sips from\n"+
"his flask with his left hand.  He looks like he's barely able\n"+
"to stand, yet at the same time, he exudes a nearly suicidal\n"+
"confidence.\n"
);
  set_gender("male");
  set_race("dwarf");
  set_level(15);
  set_wc(20);
  set_ac(9);
  set_hp(258);
  set_al(0);
  add_money(4000+random(500));
/*   set_chat_chance(8);
  set_a_chat_chance(15);
  set_chance(10);
  set_spell_mess1("Pippin pokes "+attacker_ob->query_name()+"in the eyes with two fingers.\n");
  set_spell_mess2("Pippin pokes you in the eyes with two fingers!\n");
  set_spell_dam(5);
*/
  load_a_chat("Pippin bends over and moons you.\n");
  load_a_chat("Pippin snakes his leg behind you and pushes hard.\n"+
              "You fall over in a heap.\n");
}
hit_player(arg,ob) {
  if (arg>30) 
    tell_room(environment(),
"Pippin takes the pot off of his head and with one smooth gesture,\n"+
"blocks the blow.\n");
  else
    return ::hit_player(arg,ob);
}
heal_self(arg) {
  if(arg<-30)
    tell_room(environment(),
"Pippin blocks your spell with his Frying Pan o' Doom(tm)\n");
  else
    ::heal_self(arg);
}
