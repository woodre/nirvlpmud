
#include "../DEFS.h"

status main(string str) {
  if(!call_other(OFFICED, "checkStone", TP, "diamond sapphire pearl ruby emerald onyx")) return 0;
  if(!str) {
    write("Who do you wish to report giving task(s) to?\n");
    return 1; 
  }
write_file(LOGDIR + "/TASK",
    TRN+" has given task(s) to "+str+"  ("+ctime()+")\n");
  write("You file for your recruit.\n");
  return 1;
}
