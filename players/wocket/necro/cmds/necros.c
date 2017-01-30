#include "../defs.h"

cmd(str){
 if(!GOB) return 0;
  CHAT_D->guildwho();
  return 1;
}