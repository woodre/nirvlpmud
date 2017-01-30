#include "/players/fred/ansi.h"
inherit "/obj/treasure.c";
reset (arg) {
	set_id("collar");
	set_short("A"+RED+" Cat"+NORM+" Collar");
	set_long("This is a red collar worn by none other than\n"+
               "Mr. Kitty.\n");
      set_value(100);
      set_weight(1);
}
