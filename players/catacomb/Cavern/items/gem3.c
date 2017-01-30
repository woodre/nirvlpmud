inherit "/obj/treasure.c";
#include <ansi.h>

reset (arg) {
	set_id("diamond");
	set_short("A glittering "+HIW+"diamond"+NORM);
	set_long(
      "  The diamond is one of the largest gems you have ever seen.\n"+
      "The gem could fetch a good price at any shop.\n");
      
      set_weight(2);
      set_value(1500);
}


