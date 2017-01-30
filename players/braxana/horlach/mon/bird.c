#include "/players/mythos/closed/guild/def.h"
inherit "players/mythos/closed/guild/spells/monster2";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("blood");
  set_alias("blood bird");
  set_race("bird");
  set_short(RED+"Blood Bird"+NORM);
  set_long("A blood red bird about the size of a raven.  Its beady\n"+
           "eyes seem to pierce your soul.  Razor sharp claws and beak\n"+
           "reflect what little light you have brought.  It hungers.\n");
  set_level(16);
  set_hp(400);
  set_al(-1000);
  set_wc(20);
  set_ac(12);
  set_wander();
  set_heal(2,10);
  set_aggressive(1);
  set_intel(10);
  set_a_chat_chance(20);
  load_a_chat("A bird dives at you!\n");
  load_a_chat("Something screams!\n"); 
  set_mult(2);
  set_mult_chance(25);
  set_mult_dam1(1);
  set_mult_dam2(16);
}
