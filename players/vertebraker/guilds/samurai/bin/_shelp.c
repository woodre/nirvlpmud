#include "../def.h"

cmd_shelp(str)
{
  if(!str) str = "help";
  cat(ROOTDIR+"doc/"+str);
  write("\n");
  return 1;
}