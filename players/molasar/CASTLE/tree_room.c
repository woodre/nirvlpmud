
#include "std.h"

reset(arg) {
     if(!arg)
       set_light(1);
     extra_reset();
}

object bag, fire;

extra_reset() {
      if(!present("bag")) {
        bag = clone_object("obj/bag");
        fire = clone_object("players/molasar/OBJ/firebreather");
        transfer(fire, bag);
        move_object(bag, this_object());
      }
}

short() { return "Up an oak tree"; }

long() {
     write("You are at the top of an oak tree in the garden of the castle.\n");
     write("You have a view of the shops and pub to the south and the main\n");
     write("castle to the west.\n");
     write("   There is one obvious exit:  down\n");
}

init() {
     add_action("down","down");
}

down() {
     call_other(this_player(),"move_player",
                    "down#players/molasar/CASTLE/garden2");
     return 1;
}

