inherit "obj/monster";
reset(arg) {
::reset(arg);
 if(!arg) {
  object item;
set_name("vulture");
set_alias("vulture");
set_alias("bird");
set_short("A large vulture");
set_long("A large vulture with an english accent\n"+
         "and a hair cut like Ringo Starr. He hops up\n"+
         "and down on a barren branch that is his perch,\n"+
         "squaking back and forth with his comrads.\n");
set_aggressive(0);
set_ac(12);
set_wc(20);
set_level(15);
set_hp(225);
set_chat_chance(5);
load_chat("Vulture says: What ya wanna do?\n");
set_a_chat_chance(45);
load_a_chat("Vulture swoops down at you, trying to gouge out your eyes.\n");
load_a_chat("Vulture hops up and says: This isn't what I had in mind!!\n");
set_chance(20);
set_spell_dam(20);
    }
  }
