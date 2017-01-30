#include "/players/jamila/define.h"

inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  set_dead_ob(this_object());
  if(arg) return;
  set_name("shark");
  set_alt_name("shark");
  set_alias("tiger");
  set_short("Tiger Shark");
  set_long(
"The tiger shark is a magnificent fish that owns the water\n"+
"it moves through.  It is one of the stronger preditors in\n"+
"the ocean and you are not surprised to see no small fish\n"+
"swimming in the area.\n"
  );
  set_gender("male");
  set_race("fish");
  set_level(20);
  set_wc(30+random(2));
  set_ac(14+random(2));
  set_hp(490+random(20));
  set_al(-200);
  set_chat_chance(6);  
  set_a_chat_chance(6);
  load_chat("The tiger shark swims around you.\n");
  load_a_chat("The tiger shark slashes the water with his tail.\n");
  set_chance(6);
  set_spell_mess1(
"\n\tThe tiger shark darts at its opponent with its mouth wide open\n"+
"\t\tand bites at them viciously.\n\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
"\n\tThe tiger shark darts at you with its mouth wide open and bites\n"+
"\t\tat you viciously.\n\n"
  ); /* 1ST PERSON */
  set_spell_dam(10);
}
monster_died() {
object gold;
tell_room(environment(this_object()),
  "The tiger shark's body falls limp and through one of\n"+
  "the slashes in its skin you see the glimmer of gold.\n");
  gold = clone_object("obj/money");
  gold->set_money(3500+random(500));
  move_object(gold,environment(this_object()));
return 1; }
