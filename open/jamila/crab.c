#include "/players/jamila/define.h"

inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  set_dead_ob(this_object());
  if(arg) return;
  set_name("small crab");
  set_alt_name("crab");
  set_alias("crab");
  set_short("A Small Crab");
  set_long(
"This small crab has its claws at the ready to fight off any\n"+
"preditors or anything else willing to play with it.  Move \n"+
"carefully around this little critter to not get its attention\n"+
"focused on you.\n"
  );
  set_gender("male");
  set_race("crustacean");
  set_level(4);
  set_wc(8+random(2));
  set_ac(4+random(2));
  set_hp(55+random(15));
  set_al(100);
  set_chat_chance(6);  
  set_a_chat_chance(10);
  load_chat("The small crab runs around holding its claws high.\n");
  load_a_chat("The crab charges with it's small claws snapping.\n");
  set_chance(6);
  set_spell_mess1(
"\n\tThe small crab jumps at its opponent with its small claws snapping\n"+
"\t\tand cutting through their flesh.\n\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
"\n\tThe small crab jumps at you with its small claws snapping and \n"+
"\t\tcutting through your flesh.\n\n"
  ); /* 1ST PERSON */
  set_spell_dam(3);
}
monster_died() {
object gold;
tell_room(environment(this_object()),
  "The crab dies and you can see some coins laying in\n"+
  "the dirt. It appears that he was guarding them.\n");
  gold = clone_object("obj/money");
  gold->set_money(100+random(50));
  move_object(gold,environment(this_object()));
return 1; }
