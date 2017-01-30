inherit "/obj/treasure.c";
#include <ansi.h>

reset (arg) {
	set_id("wings");
	set_short("A set of bat wings");
	set_long(
      "  A simple set of bat wings able to be sold to a shaman or\n"+
      "anyone else interested in them.\n");
      
      set_weight(1);
      set_value(600);
}


