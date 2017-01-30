#include "../DEFS.h"

status main(string str) {
  write("You restart your mechanical heart...\n");
  IPTP->reset(0);
  return 1;
}
