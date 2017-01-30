inherit "/obj/treasure.c";
#include <ansi.h>

reset (arg) {
	set_id("platter");
	set_short(HIW+"A silver serving platter"+NORM);
	set_long(
      "  A fine piece of sterling silver.  It has been polished to\n"+
      "a very bright shine.  You can see your face within the plate.\n");
      set_value(500);
      set_weight(1);
}
