
#include "std.h"

reset(arg) {
     if(!arg)
       set_light(0);
     extra_reset();
}

object orc, sword, shield;

extra_reset() {
     if(!present("orc")) {
       orc = clone_object("players/molasar/MONSTERS/orc_soldier");
       sword = clone_object("players/molasar/WEAPONS/sword");
       shield = clone_object("players/molasar/ARMOR/wood_shield");
       move_object(orc, this_object());
       transfer(sword, orc);
       transfer(shield, orc);
       call_other(orc, "init_command", "wield sword");
       call_other(orc, "init_command", "wear shield");
     }
}

init() {
     add_action("up","up");
     add_action("south","south");
}

up() {
     call_other(this_player(),"move_player",
                    "up#players/molasar/UNDER/tunnel11");
     return 1;
}

south() {
     call_other(this_player(),"move_player",
                    "south#players/molasar/UNDER/tunnel13");
     return 1;
}

short() { return "A tunnel underneath the mountain"; }

long() {
     write("A tunnel underneath the mountain.  Crude steps lead up through\n");
     write("a hole in the ceiling while the tunnel continues south.\n");
     write("   There are two obvious exits:  south and up\n");
}

