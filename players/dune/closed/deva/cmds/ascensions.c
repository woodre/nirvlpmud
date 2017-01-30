/*
 * ASCENSIONS command for Ascension
 * list of guild levels
 */
#include "../def.h"

status main() {
  write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  LEVELD->display_levels();
  write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  return 1;
}
