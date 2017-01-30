
#include "std.h"

#undef EXTRA_RESET

#define EXTRA_RESET extra_reset();

extra_reset() {
     object gull;
     if(!present("gull 3")) {
          while(!present("gull 3")) {
               gull=clone_object("players/bastion/monster/gull");
               move_object(gull, this_object()); }
          }
}

THREE_EXIT("players/bastion/isle/grass3", "north",
           "players/bastion/isle/rocky2", "east",
           "players/bastion/isle/sandybeach", "northwest",
           "Rocky shore",
           "You stand on the rocky shore of a small island.\n" +
           "The rocks and pebbles are less numerous here. The screeching of\n" +
           "gulls fills the air as they circle overhead and land on the\n" +
           "beach. The shore continues to the east and becomes sandy to the\n" +
           "northwest. Tall grass rises up to the north.\n",
           1)
