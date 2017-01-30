
#include "std.h"

reset(arg) {
     if(!arg)
       set_light(0);
     extra_reset();
}

object orc, cloth, spear, shield, helmet, armor;

extra_reset() {
     if(!present("orc")) {
       orc = clone_object("players/molasar/MONSTERS/orc_capt");
       cloth = clone_object("players/molasar/TREASURE/cloth");
       spear = clone_object("players/molasar/WEAPONS/spear");
       shield = clone_object("players/molasar/ARMOR/wood_shield");
       helmet = clone_object("players/molasar/ARMOR/orc_helm");
       armor = clone_object("players/molasar/ARMOR/orc_leather");
       move_object(orc, this_object());
       transfer(cloth, orc);
       transfer(spear, orc);
       transfer(shield, orc);
       transfer(helmet, orc);
       transfer(armor, orc);
       call_other(orc, "init_command", "wield spear");
       call_other(orc, "init_command", "wear armor");
       call_other(orc, "init_command", "wear shield");
       call_other(orc, "init_command", "wear helmet");
     }
}

init() {
     add_action("north","north");
     add_action("up","up");
}

north() {
     call_other(this_player(),"move_player",
                    "north#players/molasar/UNDER/tunnel5");
     return 1;
}

up() {
     if(present("orc")) {
       write("The orc captain grabs you and throws you to the ground.\n");
       write("The orc captain says:  You're not getting past me human!\n");
       return 1;
     }
     call_other(this_player(),"move_player",
                    "up#players/molasar/UNDER/tunnel7");
     return 1;
}

short() { return "A tunnel underneath the mountain"; }

long() {
     write("A tunnel underneath the mountain.  Crude steps lead up through\n");
     write("a hole in the ceiling.\n");
     write("   There are two obvious exits:  north and up\n");
}

