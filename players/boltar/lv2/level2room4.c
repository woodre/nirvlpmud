#include "std.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();
extra_reset(){
     if(!present("machine")) 
      move_object(clone_object("players/boltar/things/bodyex.c"), this_object());
  }

THREE_EXIT("players/boltar/lv2/level2room2.c", "north",
 "players/boltar/lv2/cyberroom.c", "east",
 "players/boltar/lv2/drenter.c", "west",
	   "machine entry area",
 "This room contains what look to the parts of many old machines, yet they look\n" +
 "like nothing you have seen before.\n", 1)
