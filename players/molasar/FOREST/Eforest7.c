/* 10/11/05 Earwax: Converted to land. */

inherit "/players/earwax/housing/land.c";

#include "std.h"

reset(arg) {
   if(!arg)
     set_light(1);
   extra_reset();
   set_realm_name("Forest");
   set_lot_size(6);
   set_cost(450000);
   setup_land();
}

object rope;

extra_reset() {
   if(!present("rope")) {
     rope = clone_object("obj/rope");
     move_object(rope, this_object());
   }
}

short() { return "A clearing in the forest"; }

long() {
   write("You have reached a small clearing in the forest.\n");
   write("   There is one obvious exit:  east\n");
}

init() {
   add_action("east","east");
}

east() {
   this_player()->move_player("west#players/molasar/FOREST/forest7");
   return 1;
}

