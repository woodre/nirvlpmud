/* 07/19/07 Earwax: switched to using flags in gob */

#include "../def.h"

cmd_kiai(str){
  object atk;
  
  if(TP->query_guild_rank() < 1) return 0;
  if(TP->query_ghost()) return 0;
  if(!(atk = TP->query_attack()))
  {
    write("You must be in combat to kiai.\n");
    return 1;
  }
  
  if(present(GOBID, TP)->query_kiai()){
    write("You are already engaged in a kiai.\n");
    return 1;
  }
  write("You "+BOLD+"KIAI"+NORM+" loudly at "+
    atk->query_name()+"!\n");
  say(TP->query_name()+" "+BOLD+"KIAIS"+NORM+
    " loudly at "+atk->query_name()+"!\n");
  
  present(GOBID, TP)->set_kiai();
  return 1;
}
