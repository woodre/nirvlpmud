#include "../DEFS.h"

status main(string str) {
if(!call_other(OFFICED, "checkStone", TP, "diamond")) return 0;
write("You check the Renegade Reports.\n");
  call_other(MORED, "more_file", LOGDIR+"/RENREPORT");
  return 1;
}
