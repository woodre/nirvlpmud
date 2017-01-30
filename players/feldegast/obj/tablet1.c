#include "defs.h"

inherit "/obj/treasure.c";

void reset(int arg) {
  if(arg) return;
  set_id("tablet");
  set_alias("fragment");
  set_short("A tablet fragment");
  set_long(
    "You can make out a few words etched into this fragment of tablet.\n"
  );
  set_weight(2);
  set_value(500);
}

void init() {
  add_action("cmd_read","read");
}

int cmd_read(string str) {
  if(this_object()!=present(str,TP)) {
    notify_fail("Read what?\n");
    return 0;
  }
  write("The tablet fragment says:\n"+
        BOLD+"\tThe four elemental keys\n"+
        "\tWater must be balanced\n"+
        "\tthe field of protection\n"+
        "\tfree to enter our world.\n"+NORM);
  return 1;
}
