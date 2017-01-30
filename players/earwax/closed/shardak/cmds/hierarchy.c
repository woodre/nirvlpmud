#include "../include/daemons.h"

status
main(string arg) {

  string *output;
  int i, siz;

  siz = sizeof(output = (string *) HIERARCHYD->dump_hierarchy());

  for (i = 0; i < siz; i++)
    write(output[i]);

  return 1;
}
