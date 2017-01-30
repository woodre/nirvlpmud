#include "defs.h"

inherit "/obj/treasure.c";

void reset(int arg) {
  if(arg) return;
  set_id("claws");
  set_alias("demon claws");
  set_short(BOLD+BLK+"Black demon claws"+NORM);
  set_long(
    "These are the dark black claws of a major demon.\n"
  );
  set_weight(1);
  set_value(800+random(400));
}
