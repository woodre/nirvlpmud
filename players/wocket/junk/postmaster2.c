#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/junk/monstersuit.c";

reset(arg){
  ::reset(arg);
  if(arg) return;
  set_name("fred");
  set_alias("postmaster");
  set_gender("male");
  set_race("seussian");
  set_level(15);
  set_hp(225);
  set_wc(20);
  set_ac(12);
  set_al(500);
  set_a_chat_chance(15);
  load_a_chat("Fred screams in pain.\n");
  load_a_chat("Fred wimpers from the pain.\n");

}
