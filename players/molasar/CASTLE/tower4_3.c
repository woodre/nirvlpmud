


#include "std.h"

int opened;

id(str) { return str == "hatch"; }

reset(arg) {
    if(!arg)
      set_light(1);
    opened = 0;
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

long(str) {
     if(str == "hatch") {
       if(opened == 1) {
         write("A large metal hatch (open)\n");
         return 1;
       }
       write("A large metal hatch.\n");
       return 1;
     }
     write("You have reached the top of the southwestern tower of the castle.\n");
     write("This point serves as a lookout for advance warning of attackers.\n");
     write("Looking out the window you see cresting waves striking a sandy beach.\n");
     write("Glancing around the room you notice a hatch on the ceiling which\n");
     write("you might be able to open.\n");
     write("   There is one obviou exit:  down\n");
}


init() {
     add_action("down","down");
     add_action("open","open");
     add_action("up","up");
}

down() {
     call_other(this_player(),"move_player",
                    "down#players/molasar/CASTLE/tower4_2");
     return 1;
}

open(str) {
     if(!str) {
       write("Open what?\n");
       return 1;
     }
     if(str == "hatch") {
       if(opened == 1) {
         write("The hatch is already open.\n");
         return 1;
       }
       write("You open the hatch.\n");
       say(capitalize(this_player()->query_name())+" opens the hatch.\n");
       opened = 1;
       return 1;
     }
}

up() {
     if(opened == 0) {
       write("The hatch is closed.\n");
       return 1;
     }
     if(present("guard")) {
       write("The guard says:  You have no business up there!\n");
       return 1;
     }
     call_other(this_player(),"move_player",
                    "up#players/molasar/CASTLE/tower_top");
     return 1;
}

