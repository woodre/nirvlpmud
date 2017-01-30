#include "/players/pestilence/ansi.h"


status main(string str) {
  object * all;
  object opp;
  int i, total, hp, mhp;
  string statss, oppn;
if(this_player()->query_guild_rank() < 3){ write("You can't use this yet.\n"); return 1; }
  all = users();
  write(HIK+"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  write(HIR+"Player          Attacker            Att's Health     Where\n");
  write(HIK+"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+NORM);
  for(i=0; i < sizeof(all); i++) {
    if(all[i]->query_attack() &&
      (int)all[i]->query_invis() < (int)this_player()->query_level() ) {
      if(all[i]->query_invis() && all[i]->query_level() >= this_player()->query_level()) continue;
      if(all[i]->query_level() > 19) continue;
      opp  = (object)all[i]->query_attack();
      oppn = (string)opp->query_name();
      write(pad(capitalize((string)all[i]->query_name()), 16));
      write(pad(oppn, 20));
      hp  = (int)opp->query_hp();
      mhp = (int)opp->query_mhp();
      statss = "good shape";
      if(hp < mhp - 20) statss = "slightly hurt";
      if(hp < mhp/2)    statss = "somewhat hurt";
      if(hp < mhp/5)    statss = "bad shape";
      if(hp < mhp/10)   statss = "very bad shape";
      if(hp < mhp/20)   statss = "verge of death";
      write(" ");
      write(pad(statss, 16));
      write((string)environment(opp)->short()+"\n");
      total += 1;
      }
    }
  if(total == 0) write("Everything is calm.\n");
  write(HIK+"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+NORM);
  return 1;
}
