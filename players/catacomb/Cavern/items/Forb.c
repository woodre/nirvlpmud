inherit "/obj/treasure.c";
#include "/players/catacomb/misc/ansi.h"

reset (arg) {
	set_id("orb");
	set_short("A fire orb");
	set_long(
      "  A small orb containing the essence of a fire elemental.  A\n"+
      "roaring "+RED+"fire"+NORM+" can be seen inside the orb yearning to\n"+ 
      "be set free from its prison.\n");
      set_weight(1);
      set_value(1000);
}


