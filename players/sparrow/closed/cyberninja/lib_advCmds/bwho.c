#include "../DEFS.h"
#define LEVEL  3

status main(string str) {
  object * all;
  object opp;
  int i, total, hp, mhp;
  string statss, oppn;

  if(!gotrank(TP, LEVEL)) return 0;
  all = users();
  write(LINE+BOLD+YELLOW);
  write("Player          Opponent            Opp's Health     Location\n");
  write(OFF+LINE);
  for(i=0; i < sizeof(all); i++) {
    if(all[i]->query_attack() &&
       (int)all[i]->query_invis() < (int)TP->query_level() ) {
      if(all[i]->query_invis() && all[i]->query_level() >= TP->query_level()) continue;
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
  if(total == 0) write("Nobody is in battle.\n");
  write(LINE);
  return 1;
}
