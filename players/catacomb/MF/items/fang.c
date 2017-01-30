#include "/players/catacomb/misc/ansi.h"
inherit "/obj/treasure.c";

reset (arg) {
	set_id("fang");
	set_short(WHT+"A viper fang"+NORM);
	set_long(
      "  A small piece of ivory that is curved into the shape of a \n"+
      "crescent moon.  Careful, the fang might still have some poison\n"+ 
      "within it.\n");
      set_value(700);
      set_weight(1);

}
