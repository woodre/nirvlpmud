#include "/players/feldegast/defines.h"
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("lady cordelia");
  set_alt_name("cordelia");
  set_alias("lady");
  set_short("Lady Cordelia");
  set_long(
"Lady Cordelia is a tall woman with gray at her temples\n"+
"and the wisdom of years of experience etched onto her\n"+
"face.  At one time she was a great beauty, but since\n"+
"her husband died time has treated her harshly.  As the\n"+
"matriarch of House Goran, she sees to many of her family's\n"+
"domestic affairs.\n"
);
  set_gender("female");
  set_race("human");
  set_level(17);
  set_wc(24);
  set_ac(14);
  set_hp(400);
  set_al(900);
  add_money(950);
  set_a_chat_chance(5);
  load_a_chat("Lady Cordelia assumes an attack stance.\n");
  load_a_chat("Lady Cordelia chops her opponent's neck.\n");
  load_a_chat("Lady Cordelia moves with astonishing strength and speed.");
  load_a_chat("Lady Cordelia strikes her foe with a roundhouse kick\n"+
              "to the jaw.");
  load_a_chat("Lady Cordelia blows a puff of some strange powder in her\n"+
              "opponent's face.");
  set_chance(15);
  set_spell_mess1(
"\nLady Cordelia produces a throwing knife from her gown.\n"+
"Almost simultunaeously, a "+RED+"red stain"+NORM+"blossoms on her"+
"opponent's torso and the knife disappears from her hand.\n\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
"\nLady Cordelia produces a throwing knife from her gown.\n"+
"Almost simultunaeously, a "+RED+"red stain"+NORM+"blossoms on your"+
"torso and the knife disappears from her hand.\n\n"
  
  ); /* 1ST PERSON */
  set_spell_dam(15);
}
