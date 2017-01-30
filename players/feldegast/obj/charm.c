#include "defs.h"

inherit "/obj/treasure.c";

void reset(int arg) {
  if(arg) return;
  set_id("charm");
  set_alias("illusion countermeasures");
  set_short("A magic charm");
  set_long(
    "This is a lucky magic wisdom tooth.  You assume it actually\n"+
    "has some use.\n"
  );
  set_weight(1);
  set_value(50);
}
