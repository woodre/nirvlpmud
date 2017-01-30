#include "defs.h"

status main(string arg)
{
  write(RED+"------------------------------------------------------------------------------\n"+NORM+NORM);
  write(HIK+"Servants of Shardak Local News"+NORM+NORM+"\n");
  write(RED+"------------------------------------------------------------------------------\n"+NORM+NORM);
  tail(NEWS);
  write(RED+"------------------------------------------------------------------------------\n"+NORM+NORM);
  return 1;
}
