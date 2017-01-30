#include "../DEFS.h"

status main(string str) {
  call_other(MEMBERD, "restoration", TP);
  write("Your implants have been restored.\n");
  return 1;
}
