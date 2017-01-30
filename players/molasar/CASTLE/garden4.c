
#include "std.h"

reset(arg) {
     if(!arg)
       set_light(1);
     extra_reset();
}

object well;

extra_reset() {
     if(!present("well")) {
       well = clone_object("players/molasar/OBJ/well");
       move_object(well, this_object());
     }
}

init() {
     add_action("north","north");
     add_action("east","east");
     add_action("northeast","northeast");
}

north() {
     call_other(this_player(),"move_player",
                    "north#players/molasar/CASTLE/garden3");
     return 1;
}

east() {
     call_other(this_player(),"move_player",
                    "east#players/molasar/CASTLE/garden1");
     return 1;
}

northeast() {
     call_other(this_player(),"move_player",
                      "northeast#players/molasar/CASTLE/garden2");
     return 1;
}

short() { return "A garden"; }

long() {
     write("A large stone well dominates this part of the garden.  Small\n");
     write("plants and shrubbery lie around the well, while small bricks\n");
     write("outline a path up to the well.\n");
     write("   There are three obvious exits:  north, east, northeast\n");
}


