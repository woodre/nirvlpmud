#include "../DEFS.h"

status main(string str) {
  if(!call_other(OFFICED, "checkStone", TP, "diamond sapphire onyx")) return 0;
  if(!str) {
    write("What do you wish to report?\n");
    write("Remember to include the name of the tournament.\n");
    return 1; 
  }
  write_file(TOURNDIR + "/reports",
    TRN+" reports: "+str+"  ("+ctime()+")\n");
  write("You file your report.\n");
  return 1;
}
