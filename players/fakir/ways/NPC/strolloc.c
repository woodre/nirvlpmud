#include "/players/fakir/color.h"
inherit "/obj/monster";
reset(arg)  {
  object treasure;
  ::reset(arg);
  if(arg) return;
  set_name("trolloc");
  set_alt_name("scout");
  set_alias("troll");
  set_race("creature");
  set_short("A Trolloc Scout");
  set_long(
"   A creature of the Dark One, created during the war of the shadow.\n"+
"Smaller than most other trollocs, this one has large ears and a very\n"+
"keen sense of smell.  He serves the fist as a scout, tracking down\n"+
"those they seek.  Sly, deceitful, and treacherous, he can be trusted\n"+
"only by those he fears.  He holds a curved rams horn which he uses to\n"+
"call the fist to battle.\n");
  set_level(12);
  set_hp(180);
  set_al(-600);
  set_wc(16);
  set_ac(9);
  set_dead_ob(this_object());
  set_chat_chance(15);
  load_chat("The trolloc scout blows loudly into his horn...OOOOaaaggg...OOOOaaaggg.\n");
  set_a_chat_chance(15);
  load_a_chat("The trolloc thwops you across the face with his horn.\n");
  set_chance(10);
  set_spell_dam(10 +random(5));
  set_spell_mess1("The trolloc rushes inside your guard and strikes.\n");
  set_spell_mess2("The trolloc moves with the grace of a cat. \n"); 

  treasure=clone_object("/players/fakir/ways/OBJ/horn.c");
  move_object(treasure,this_object());

}

monster_died() {
  tell_room(environment(this_object()),
 MAGENTA+"The trolloc's fingers spasm and release their hold on the horn."+OFF+" \n");
  return 0; }
