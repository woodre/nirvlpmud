#include "../def.h"

cmd_kill(str)
{
  object obj;
  if(!str) return 0;
  
  if(!present(str,ENV(TP))) return 0;
  
  write("\n\tYou shout: "+HIY+"B A N Z A I"+NORM+" !\n\n");
  say(TP->QN+" shouts: "+HIY+"B A N Z A I"+NORM+" !\n\n");
  return 0;
}