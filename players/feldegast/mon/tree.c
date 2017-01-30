/*
Name: tree.c
Author: Feldegast
Date: 5/7/98
Revised: 10/24/01
Description:
  A vicious oak tree, appearing randomly in Caladon.  I made it a
long time ago for another area.  Time to use it again.
*/
#include "/players/feldegast/defines.h"

inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("tree");
  set_alt_name("oak");
  set_alias("oak tree");
  set_short(BOLD+BLK+"A gnarled oak tree"+NORM);
  set_dead_ob(this_object());
  set_long(
    "This is a gnarled old oak tree with few leaves remaining upon\n"+
    "its wizened and decaying trunk.  It's shadowy black bark is\n"+
    "twisted in dark patterns, almost like human faces stretched in\n"+
    "expressions of horror and misery.\n"
  );
  set_race("plant");
  set_level(20);
  set_wc(26+random(8));
  set_ac(15+random(4));
  set_hp(480+random(70));
  set_al(-350);
  set_chat_chance(5);
  load_chat("The gnarled old oak's limbs lean into the wind, almost\n"+
            "as though it were trying to resist nature itself.\n");
  set_a_chat_chance(9);
  load_a_chat("The gnarled old oak moves with surprising speed as it\n"+
              "strikes with its long curving limbs.\n");
  set_chance(20);
  set_spell_mess1(
    "The gnarled old oak flays its foe with hidden thorns.\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
    "\nThe gnarled old oak flays you with hidden thorns.\n"
  ); /* 1ST PERSON */
  set_spell_dam(30);
}

monster_died() {
  object wood;
  wood=clone_object("/players/feldegast/obj/magic_wood");
  move_object(wood,environment());
  say("\nThe gnarled old oak falls to the forest floor, all life\n"+
      "gone from its body.\n");
}
