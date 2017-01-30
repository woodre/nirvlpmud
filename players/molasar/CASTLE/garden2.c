#include "std.h"  /* Rumplemintz - 10/24/07 */

reset(arg) {
     if(!arg)
       set_light(1);
     extra_reset();
}

object tree;

extra_reset() {
     if(!present("tree")) {
       tree = clone_object("players/molasar/OBJ/tree");
       move_object(tree, this_object());
     }
}

init() {
     add_action("south","south");
     add_action("west","west");
     add_action("southwest","southwest");
     add_action("north","north");
}

north() {
     call_other(this_player(),"move_player",
                    "north#players/molasar/CASTLE/road4");
     return 1;
}

south() {
     call_other(this_player(),"move_player",
                    "south#players/molasar/CASTLE/garden1");
     return 1;
}

west() {
     call_other(this_player(),"move_player",
                    "west#players/molasar/CASTLE/garden3");
     return 1;
}

southwest() {
     call_other(this_player(),"move_player",
                    "southwest#players/molasar/CASTLE/garden4");
     return 1;
}

short() { return "A Garden"; }

long() {
     write("Much of the flora has cleared out making room for a giant oak\n");
     write("tree, undoubtedly the largest of the kind you have seen.  The\n");
     write("base of the tree is encircled by small plants and some type\n");
     write("small barricade to keep small animals out.  A small road leads\n");
     write("north from behind the tree.\n");
     write("   There are three obvious exits:  north, south, west, southwest\n");
}

