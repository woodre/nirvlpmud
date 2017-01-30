#include "/players/linus/def.h"
inherit "/players/vertebraker/closed/std/monster.c";
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("linus_angel_mob");
  set_short("A small mouse");
  set_long(
 "A small mouse that resides in a ruined mansion.  It scampers about\n"+
 "in search of food.\n");
  set_race("mouse");
  set_level(5);
  set_wc(10);
  set_ac(6);
  set_hp(75+random(50));
  set_al(100);
  set_chat_chance(4);
  load_chat("The mouse scampers about...\n");
  load_chat("The mouse stands on his hind legs and peers around...\n");
}

