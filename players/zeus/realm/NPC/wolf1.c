inherit "/obj/monster";
#include "/players/zeus/closed/all.h"

reset(arg) {
   ::reset(arg);
   if (!arg) {

  set_name("black wolf");
  set_alias("wolf");
  set_short("A black wolf");
  set_race("wolf");
  set_long(
"A very tough looking black wolf stands before you.  It's fur is dirty\n"+
"and matted, and it has a very pungent odor.  It's fierce green eyes\n"+
"watch every detail of the room with the utmost attention.  Standing\n"+
"tall like a guardian of the forest, this wolf is a true warrior.\n");
  set_level(17+random(4));
  set_ac(17);
  set_wc(36);
  set_heal(2,1);
  set_hp(455+random(25));
  set_aggressive(0);
  set_chat_chance(4);
  set_a_chat_chance(5);
  load_chat("The wolf glares into your eyes.\n");
  load_chat("The wolf breathes slowly.\n");
  load_chat("The wolf growls deeply.\n");
  load_chat("The wolf moves slowly as it watches you.\n");
  load_a_chat("The wolf hits you with a crushing blow!\n");
  load_a_chat("The wolf bites into you with it's mighty jaws!\n");
  load_a_chat("The wolf lunges at you!\n");
  set_chance(15);
  set_spell_dam(25);
  set_spell_mess1("The wolf snaps at you!\n");
  set_spell_mess2("The wolf bites you hard!\n");
  set_dead_ob(this_object());
   }
}

monster_died(){
  write("As the wolf dies you notice something on the ground.\n");
  MO(CO("/players/zeus/realm/OBJ/wolfhair.c"), environment());
  return 1; 
}
