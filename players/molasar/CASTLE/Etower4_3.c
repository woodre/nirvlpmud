


#include "std.h"

reset(arg) {
    if(!arg)
      set_light(1);
    extra_reset();
}

object guard, sword, armor;

extra_reset() {
     if(!present("guard")) {
       armor = clone_object("players/molasar/ARMOR/leather_armor");
       sword = clone_object("players/molasar/WEAPONS/shortsword");
       guard = clone_object("players/molasar/MONSTERS/tower_guard");
       transfer(armor, guard);
       transfer(sword, guard);
       move_object(guard, this_object());
       call_other(guard,"init_command","wield sword");
       call_other(guard,"init_command","wear leather armor");
     }
}

short() { return "The top of the tower"; }

long() {
     write("You have reached the top of the southwestern tower of the castle.\n");
     write("This point serves as a lookout for advance warning of attackers.\n");
     write("Lookin out the window you see numerous clouds of dust rolling\n");
     write("across an endless desert.\n");
     write("   There is one obviou exit:  down\n");
}

init() {
     add_action("down","down");
}

down() {
     call_other(this_player(),"move_player",
                    "down#players/molasar/CASTLE/tower4_2");
     return 1;
}

