/*
 A sand squid for near the rocks in the Jal-Hab desert.
 3-8-2000
 */
#include "defs.h"

inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("sand squid");
  set_alt_name("squid");
  set_short(0); /* Slightly invisible */
  set_long(
    "The sand squid is a squid-like creature approximately one meter long from\n"+
    "tail to tentacle that burrows through the sand and pops up only to attack\n"+
    "its prey.\n"
  );
  set_gender(0);
  set_race("critter");
  set_level(11);
  set_wc(15);
  set_ac(9);
  set_hp(165);
  set_al(0);
  set_chat_chance(5);
  load_chat("You hear a soft 'swish-swish' sound.\n");
  load_chat("The sand ripples.\n");
  set_a_chat_chance(5);
  load_a_chat("A sand squid burrows up out of the sand and bites its prey with\n"+
              "its vicious little teeth.\n");
  load_a_chat("The sand squid lets out a piercing shriek that echoes among the rocks.\n");
  set_aggressive(1);
  set_dead_ob(this_object()); 
}

void monster_died(object ob) {
  move_object(clone_object(HEAL_PATH+"sliver.c"),this_object());
  write("You slit open the squid's belly and cut out its liver.\n");
}
