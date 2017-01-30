#include "room.h"

init() {
     ::init();
     add_action("look", "look");
     add_action("look", "l");
     add_action("look", "examine");
}

look(str) {
  if (!str) return 0;
  if (str == "at shop") {
    write("A small squarish brick building with no windows on this side.\n"+
    "The entrance is to the west along the north side of the main road.\n");
    return 1;
  }
  if (str == "at adventures guild" || str == "at guild") {
    write("The Adventurer's guild is a small stone building with odd \n"+
      "symbols carved into the walls. The entrance is on the south side\n"+
      "of the road west along the main road.\n");
  return 1;
  }
 return 0;
}

#undef EXTRA_RESET
#define EXTRA_RESET no_castle_flag = 1;
FOUR_EXIT("room/vill_shore","east",
	   "room/northroad1.c","north",
	   "room/southroad1.c","south",
	   "room/vill_road2","west",
	   "Village road",
"A long road going east and west through the village. To the northwest is\n"+
"the main shop, to the southwest the Adventurer's guild. There is a crossroad\n"+
"heading north and south, with what looks like a bunch of small shops to the\n"+
"north.\n", 1)
