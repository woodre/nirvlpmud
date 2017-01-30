#include "../DEFS.h"

status main(string str) {
  if(!call_other(OFFICED, "checkStone", TP, "diamond sapphire pearl ruby emerald onyx")) return 0;
  write("Logging into the task matrix...\n");
  call_other(MORED, "more_file", LOGDIR+"/TASK");
  return 1;
}
