#include "/players/mythos/closed/guild/def.h"
int tim;
inherit "players/mythos/closed/guild/spells/monster2";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("horlach");
  set_short("A cloaked figure");
  set_alias("figure");
  set_race("hunter");
  set_long("A dark figure.\n");
  set_hp(10000);
  set_level(30);
  set_al(0);
  set_wc(100);
  set_ac(30);
  set_aggressive(0);
  set_heal(100,5);
  set_chat_chance(3);
  set_a_chat_chance(15);
  load_chat("The wind blows...\n");
  load_chat("Time seems endless...\n");
  set_chance(25);
  set_spell_dam(300);
  set_spell_mess1("Mist gathers.\n");
  set_spell_mess2("\nYou feel great pain as Horlach lashes out with coldfire!\n");
  set_mult(3);
  set_mult_chance(90);
  set_mult_dam1(50);
  set_mult_dam2(100);
}

set_time(n) { tim = n; }

heart_beat() {
  ::heart_beat();
  
}
