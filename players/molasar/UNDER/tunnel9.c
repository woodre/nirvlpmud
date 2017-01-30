

#include "std.h"

reset(arg) {
     if(!arg)
       set_light(0);
     extra_reset();
}

object man, pick, stonecutter;

extra_reset() {
     if(!present("man")) {
       man = clone_object("players/molasar/MONSTERS/prospector");
       pick = clone_object("players/molasar/WEAPONS/pick_axe");
       stonecutter = clone_object("players/molasar/TREASURE/stonecutter");
       move_object(man, this_object());
       transfer(pick, man);
       transfer(stonecutter, man);
       call_other(man, "init_command", "wield pick axe");
     }
}

init() {
     add_action("north","north");
}

north() {
     call_other(this_player(),"move_player",
                    "north#players/molasar/UNDER/tunnel8");
     return 1;
}

short() { return "A dead end"; }

long() {
     write("This is the dead end of the tunnel.  Many rocks and old rotted\n");
     write("equipment lie strewn about about the floor.  Marks on the wall\n");
     write("show that someone has been trying to dig through.\n");
     write("   There is one obvious exit:  north\n");
}

