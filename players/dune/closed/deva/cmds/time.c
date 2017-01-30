/*
 * TIME command for Ascension
 * look at mud time
 */
#include "../def.h"

status main() {
/* Command to find time on church clock */
  call_other("/room/church.c","long","clock");
  write("\nTime: "+ctime(time())+"\n");
  return 1;
}
