inherit "/obj/treasure.c";
#include <ansi.h>

reset (arg) {
	set_id("onyx");
	set_short("A brilliant "+BLK+"onyx"+NORM+".");
	set_long(
      "  The onyx is one of the largest gems you have ever seen.\n"+
      "The gem could fetch a good price at any shop.\n");
      
      set_weight(2);
      set_value(1000);
}


