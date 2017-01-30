#include "../DEFS.h"

status main(string str) {
if(!call_other(OFFICED, "checkStone", TP, "diamond")) return 0;
  if(!str) {
write("Only Directives can write on the renegade report.\n");
    return 1; 
  }
write_file(LOGDIR + "/RENREPORT",
TRN+" has filed a renegade report on: "+str+"  ("+ctime()+")\n\n");
write("You created a new renegade report.\n");
  return 1;
}
