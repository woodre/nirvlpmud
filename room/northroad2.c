#include "room.h"

init() {
     ::init();
     add_action("look", "look");
     add_action("look", "l");
     add_action("look", "examine");
}

look(str) {
  if (!str) return 0;
  if (str == "at trail") {
     write("A well worn dirt foot-path.\n");
     return 1;
   }
  return 0;
}

#undef EXTRA_RESET
#define EXTRA_RESET no_castle_flag = 1;
THREE_EXIT("room/northroad1","south",
            "room/northroad3","north",
            "players/boltar/sprooms/arena", "northeast",
	   "Village road(Northroad)",
"Northroad is a worn cobblestone road that runs north and south through\n"+
"the village. The business district is to either side and the road\n"+
"continues to the north or south to the village's main road. There is a\n"+
"trail to the arena to the northeast and a hotel to the east.\n",1)
