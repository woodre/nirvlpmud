inherit "/obj/treasure.c";
#include <ansi.h>

reset (arg) {
	set_id("sapphire");
	set_short("A brilliant "+BLU+"sapphire"+NORM+".");
	set_long(
      "  The sapphire is one of the largest you have ever seen.\n"+
      "The gem could fetch a good price at any shop.\n");
      
      set_weight(2);
      set_value(1000);
}


