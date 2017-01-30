

int state;
#include "std.h"

reset(arg) {
    if(!arg)
      set_light(1);
      extra_reset();
}

object gate, guard, armor, buckler, sword;
int i;

extra_reset() {
     i = 0;
     if(!present("gate guard")) {
       while(i < 2) {
       i += 1;
       guard = clone_object("players/molasar/MONSTERS/gate_guard");
       sword = clone_object("players/molasar/WEAPONS/sword");
       armor = clone_object("players/molasar/ARMOR/leather_armor");
       buckler = clone_object("players/molasar/ARMOR/buckler");
       move_object(guard, this_object());
       transfer(sword, guard);
       transfer(armor, guard);
       transfer(buckler, guard);
       call_other(guard, "init_command", "wear leather armor");
       call_other(guard, "init_command", "wear buckler");
       call_other(guard, "init_command", "wield sword");
       }
     }
     if(!present("gate")) {
       gate = clone_object("players/molasar/CASTLE/gate");
       move_object(gate, this_object());
     }
}

short() { return "Entry to the castle"; }

long() {
     write("You have reached the entrance to the castle.  A large stone\n");
     write("arch to the west leads to the inner area of the castle.\n");
     write("A small guard booth stands on both sides of the arch.\n");
     write("   There are two obvious exits:  south and west\n");
}

init() {
    add_action("west","west");
    add_action("south","south");
}

south() {
     call_other(this_player(),"move_player",
                    "east#players/molasar/PLAINS/Eplain11");
     return 1;
}

west() {
/*  Rumplemintz - 10/24/07 - Added to check if there is a gate
    and if not, for whatever reason, to allow to move
*/
    if(present("gate") && gate->query_state() == 0) {
/*
    if(call_other(gate,"query_state") == 0) {
*/
      write("The gate bars your way.\n");
      return 1;
    }
    if(present("gate guard") && this_player()->query_alignment() < 0) {
      write("The guard blocks your path.\n");
      write("The guard says:  We don't want your kind here!\n");
      return 1;
    }
    call_other(this_player(),"move_player","west#players/molasar/CASTLE/entrance");
    return 1;
}

