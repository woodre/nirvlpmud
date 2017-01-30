#include "/players/jamila/define.h"

inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  set_dead_ob(this_object());
  if(arg) return;
  set_name("starfish");
  set_alt_name("fish");
  set_alias("starfish");
  set_short("A Starfish");
  set_long(
"This starfish is stranded here in the sand with its \n"+
"arms waving back and forth as each wave rolls over it. \n"+
"Each wave tugs the starfish a little farther away and\n"+
"into the water.\n"
  );
  set_gender("female");
  set_race("crustacean");
  set_level(6);
  set_wc(10+random(3));
  set_ac(5+random(2));
  set_hp(70+random(15));
  set_al(100);
  set_chat_chance(6);  
  set_a_chat_chance(10);
  load_chat("The starfish waves its arms.\n");
  load_a_chat("The starfish grabs at the waves with its arms.\n");
  set_chance(7);
  set_spell_mess1(
"\n\tThe starfish grabs its oppenent's leg with its arms and its\n"+
"\t\tlittle suction cups pull away small pieces of their flesh.\n\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
"\n\tThe starfish grabs your leg with its arms and its little\n"+
"\t\tsuction cups pull away small pieces of your flesh.\n\n"
  ); /* 1ST PERSON */
  set_spell_dam(3);
}
monster_died() {
object gold;
tell_room(environment(this_object()),
  "The starfish dies and you notice a small pile of coins\n"+
  "laying beneath it's body.\n");
  gold = clone_object("obj/money");
  gold->set_money(150+random(100));
  move_object(gold,environment(this_object()));
return 1; }