#include "defs.h"

inherit "/obj/treasure.c";

void reset(int arg) {
  if(arg) return;
  set_id("castle%magnarn%golden%seal");
  set_alias("seal");
  set_short(YEL+"Golden Seal"+NORM);
  set_long(
    "This appears to be an ancient artifact of some kind, a circular piece\n"+
   "of gold with an odd pattern on one face.\n"
  );
  set_weight(1);
  set_value(1000);
}
