#include "/players/stark/defs.h"
inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("sithos");
  set_alt_name("snake");
  set_short("Sithos");
  set_long(
"   Sithos is the living God of the Sithos Tribe.  The full length of \n"+
"fifty yards is curled up into a massive spring.  The burning red eyes \n"+
"of Sithos are pronounced unlike a normal snake.  Fangs normally hidden \n"+
"are extended down from his mouth.\n"
  );
  set_gender("male");
  set_race("snake");
  set_level(20);
  set_wc(30);
  set_ac(17);
  set_hp(500);
  set_al(-700);
  set_aggressive(1);
  set_a_chat_chance(5);
  load_a_chat("Sithos speaks:  You will die for this.\n");
  load_a_chat("Sithos speaks:  Where have my guardians gone?\n");
  load_a_chat("Sithos speaks:  Your flesh will sustain me for my next slumber.\n");
  load_a_chat("Sithos speaks:  The day will come when I will bring destruction to all.\n");
  set_chance(25);
  set_spell_mess1(
"\n\n      Sithos opens his mouth wide\n"+
"              and with a deafening screach\n"+
"                breaths "+RED+"blazing fire"+NORM+" onto his opponent!\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
"\n\n      Sithos opens his mouth wide\n"+
"              and with a deafening screach\n"+
"                breaths "+RED+"blazing fire"+NORM+" at you!\n"
  ); /* 1ST PERSON */
  set_spell_dam(25);
  set_dead_ob(this_object());
}

monster_died(ob){
write("\n\n   With his last bit of strength Sithos lunges at you!\n"+
          "      But his energy has drained and he slams dead into the ground\n"+
          "          One of his fangs bursts forth from his mouth and into your hands!\n\n");
  move_object(clone_object("/players/stark/forest/obj/fang.c"),this_object());
return 1;}
