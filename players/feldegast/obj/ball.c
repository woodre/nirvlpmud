#include "defs.h"

inherit "/obj/treasure.c";

void reset(int arg) {
  if(arg) return;
  set_id("ball");
  set_alias("powdery ball");
  set_short("A white ball");
  set_long("This is a small ball of some white powdery stuff that looks\n"+
          "like it would dissolve if it were tossed into a pool of water.\n");
/* That's not TOO obvious, is it? */
  set_weight(1);
  set_value(50);
}
