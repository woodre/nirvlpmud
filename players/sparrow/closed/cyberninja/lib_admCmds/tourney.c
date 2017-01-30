#include "../DEFS.h"

status main(string str) {
  if(!call_other(OFFICED, "checkStone", TP, "diamond sapphire onyx")) return 0;
  write("Looking up tournament info...\n");
  call_other(MORED, "more_file", TOURNDIR+"/reports");
  return 1;
}
