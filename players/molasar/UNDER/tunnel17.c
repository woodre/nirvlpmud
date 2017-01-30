
#include "std.h"

reset(arg) {
     if(!arg) 
       set_light(0);
     extra_reset();
}


extra_reset() {
      object orc, shield, sword;
      int i;

     i = 0;
     if(!present("orc")) {
       while(i < 2) {
         i += 1;
         orc = clone_object("players/molasar/MONSTERS/orc_soldier");
         shield = clone_object("players/molasar/ARMOR/wood_shield");
         sword = clone_object("players/molasar/WEAPONS/sword");
         move_object(orc, this_object());
         transfer(shield, orc);
         transfer(sword, orc);
         call_other(orc, "init_command", "wield sword");
         call_other(orc, "init_command", "wear shield");
       }
     }
}

init() {
     add_action("west","west");
     add_action("east","east");
}

east() {
     if(present("orc")) {
       write("An orc bars your way.\n");
       return 1;
     }
     call_other(this_player(),"move_player",
                    "east#players/molasar/UNDER/tunnel18");
     return 1;
}

west() {
     call_other(this_player(),"move_player",
                    "west#players/molasar/UNDER/tunnel16");
     return 1;
}

short() { return "A tunnel underneath the mountain"; }

long() {
    write("A tunnel underneath the mountain.  The walls begin to curve in \n");
    write("more making the walking room a bit more cramped.\n");
    write("   There are two obvious exits:  east and west\n");
}

