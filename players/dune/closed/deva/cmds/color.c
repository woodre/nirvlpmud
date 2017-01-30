/*
 * COLOR command for Ascension
 * toggle ansi color
 */
#include "../def.h"

status main() {
  if (PRE->query_setting(COLOR)) {
    write("Color is now OFF.\n");
    PRE->set_setting(COLOR, 0);
    PRE->save_me();
    }
  else {
    write("Color is now ON.\n");
    PRE->set_setting(COLOR, 1);
    PRE->save_me();
    }
  return 1;
}
