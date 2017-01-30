#include "/players/catacomb/misc/ansi.h"
inherit "/obj/treasure.c";

reset (arg) {
	set_id("wing");
	set_short(HIM+"An imp's wing"+NORM);
	set_long(
      "  A strange leather-like substance makes up the former imp\n"+
      "wings.  Although they don't appear to be much, in the right\n"+ 
      "person's hand they might be helpful.\n");
      set_value(1200);
      set_weight(1);

}
