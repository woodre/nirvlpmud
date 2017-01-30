#include "../DEFS.h"

status main(string str) {
/* Command to find time on church clock */
  call_other("/room/church.c","long","clock");
  write("\nTime: "+ctime(time())+"\n");
  return 1;
}
