#include "../defs.h"

cmd(str){
  if(str == "necro"){
write("You muffle the necromancer guild line.\n");
  GOB->set_muffle(1);
  CHAT_D->resetchannel();
return 1;
}
notify_fail("What would you like to muffle?\n");
return 0;
}
