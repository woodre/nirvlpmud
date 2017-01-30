#include "../defs.h"

cmd(str){
  if(str == "necro"){
write("You unmuffle the necromancer guild line.\n");
GOB->set_muffle(0);
CHAT_D->resetchannel();
return 1;
}
notify_fail("What would you like to unmuffle?\n");
return 0;
}
