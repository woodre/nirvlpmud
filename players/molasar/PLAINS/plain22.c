
#include "std.h"

reset(arg) {
    if(arg) return;
    set_light(1);
    extra_reset();
}

object nomad, sword, wagon;

extra_reset() {
     if(!present("nomad")) {
       nomad = clone_object("players/molasar/MONSTERS/nomad");
       sword = clone_object("players/molasar/WEAPONS/curved_sword");
       transfer(sword, nomad);
       move_object(nomad, this_object());
       nomad->init_command("wield sword");
     }
     if(!present("wagon")) {
       wagon = clone_object("players/molasar/OBJ/wagon");
       move_object(wagon, this_object());
     }
}

short() { return "A large open plain"; }

long() {
   write("You are in a large open plain.  Paths lead in all directions.\n");
   write("   There are four obvious exits:  north, south, east, and west\n");
}

init() {
     add_action("north","north");
     add_action("south","south");
     add_action("east","east");
     add_action("west","west");
}

north() {
     this_player()->move_player("north#players/molasar/PLAINS/plain21");
     return 1;
}

south() {
     this_player()->move_player("south#players/molasar/PLAINS/plain4");
     return 1;
}

east() {
     this_player()->move_player("east#players/molasar/PLAINS/plain15");
     return 1;
}

west() {
     this_player()->move_player("west#players/molasar/PLAINS/plain24");
     return 1;
}

