#include "/players/jamila/define.h"

inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  set_dead_ob(this_object());
  if(arg) return;
  set_name("seagull");
  set_alt_name("gull");
  set_alias("bird");
  set_short("A Seagull");
  set_long(
"This is a small white bird whith bits of grey covering its\n"+
"short sturdy wings.  The bird appears defenseless as it hops\n"+
"around on the ground searching for food.\n"
  );
  set_gender("unknown");
  set_race("bird");
  set_level(7);
  set_wc(10+random(2));
  set_ac(6+random(2));
  set_hp(95+random(20));
  set_al(100);
set_chat_chance(6);
  set_a_chat_chance(10);
load_chat("The seagull caws and swoops.\n");
  load_a_chat("The Seagull caws loudly above your head.\n");
  load_a_chat("The Seagull's wings flap as it swoops past you.\n");
  load_a_chat("The Seagull runs past you. \n");
  set_chance(5);
  set_spell_mess1(
"\n\tThe Seagull swoops down and its claws slice through its opponents\n"+
"\t\tskin leaving long red scratches.\n\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
"\n\tThe Seagull swoops down and it's claws slice through your skin\n"+
"\t\tleaving long red scratches.\n\n"
  ); /* 1ST PERSON */
  set_spell_dam(5);
}
monster_died() {
object gold;
tell_room(environment(this_object()),
  "As the seagull dies its body falls from the sky and\n"+
  "coins rain down with it.  The gods must be thankful\n"+
  "to be rid of these annoying creatures.\n");
  gold = clone_object("obj/money");
  gold->set_money(200+random(100));
  move_object(gold,environment(this_object()));
return 1; }