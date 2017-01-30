inherit "obj/monster";
#include "/players/illarion/dfns.h"

void reset(int arg) {
  int *stats;
  if(arg) return;
  stats=(mixed)call_other("/players/illarion/monster_stats","determine_stats",10,0);
  set_name("bandit");
  set_race("human");
  set_short("A threatening bandit");
  set_long(
"A man with a sarcastic smile and an overly casual manner, along with a \n"+
"lean and hungry look that puts you on your guard.  He wears leather and\n"+
"cloth clothes that have seen better days, and weren't all that nice to\n"+
"begin with, but he carries a serviable weapon.\n");
  set_level(10);
  set_hp(stats[0]);
  set_wc(stats[1]);
  set_ac(stats[2]);
/*
  add_money(stats[3]);
*/
  set_gender("male");
  set_al(-200);
}
