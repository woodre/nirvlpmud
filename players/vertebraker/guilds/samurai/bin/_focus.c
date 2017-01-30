/* 07/19/07 Earwax: moved from using an object to flags in gob */

#include "../def.h"

cmd_focus(str){
  object atk;
  
  if(TP->query_guild_rank() < 1) return 0;
  if(TP->query_ghost()) return 0;
  if(!(atk = TP->query_attack()))
  {
    write("You must be in combat to focus.\n");
    return 1;
  }
      
  if(present(GOBID, TP)->query_focus()){
    write("You are already focusing.\n");
    return 1;
  }
  write("You "+BOLD+"Focus"+NORM+" intently on "+
    atk->query_name()+".\n");
  say(TP->query_name()+" "+BOLD+"focuses"+NORM+
    " on "+atk->query_name()+".\n");
      
  present(GOBID, TP)->set_focus();
  return 1;
}
