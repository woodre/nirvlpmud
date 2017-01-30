#include "std.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
 object toy, light;

    if (!present("lights")) {
     light = clone_object("players/boltar/things/xmaslights.c");
   move_object(light, this_object());
}
   if (!present("top")) {
           toy = clone_object("players/boltar/things/toy.c");
       move_object(toy, this_object());
}
return 1;
}
FOUR_EXIT("players/boltar/santaland/snowtunnel.c", "down",
 "players/boltar/santaland/wkshp2.c", "south",
 "players/boltar/santaland/santa_office.c", "west",
 "players/boltar/santaland/wkshp3.c", "north",
	   "The snow before santa's place",
  "In the center of the room there is a hole in the floor leading down to \n"+
  "the tunnel.  This room is made completely of unfinshed wood, the floors, \n"+
  "the walls, everything.  There are many work benches around with half completed\n"+
  "toys on them.\n"+
  "A small elf runs by you so fast you hardly see him!\n", 1)
