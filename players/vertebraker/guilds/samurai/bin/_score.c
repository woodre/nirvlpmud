#include "../def.h"

int s;
int cmd_score(){
   if(s) return 0;
  s = 1;
  command("score", TP);
  write("Guild rank: "+TP->query_guild_rank()+"\n");
  s =0;
  return 1;
}
