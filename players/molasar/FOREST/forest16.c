/* 10/11/05 Earwax: Converted to land. */

inherit "/players/earwax/housing/land.c";

#include "std.h"

reset(arg) {
   if(!arg)
     set_light(1);
   extra_reset();
   set_realm_name("Forest");
    set_cost(300000);
   set_lot_size(2);
   setup_land();
}

object hook;

extra_reset() {
   if(!present("hook")) {
     hook = clone_object("players/molasar/MISC/hook");
     move_object(hook, this_object());
   }
}

short() { return "A clearing in the forest"; }

long() {
   write("You have reached a small clearing in the forest.\n");
   write("   There is one obvious exit:  west\n");
}

init() {
   add_action("west","west");
}

west() {
   this_player()->move_player("west#players/molasar/FOREST/forest10");
   return 1;
}

