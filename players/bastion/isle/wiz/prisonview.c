
#include "std.h"

#undef EXTRA_LONG
#define EXTRA_LONG \
     if(str=="screen"||str=="viewscreen") { \
          write("You can see into the room beyond...\n"); \
          return; } \
     if(str=="door"||str=="vault") { \
          write("It stands as a formidable obstacle.\n"); \
          return; } 

ONE_EXIT("players/bastion/isle/wiz/prison_hall", "north",
     "Prison Viewing Room",
     "You are in a small room, ten feet on a side. You notice a large\n"+
     "viewscreen on the south wall, next to a heavily vaulted door\n"+
     "covered in runes and mystical wards. A few comfortable-looking\n"+
     "chairs are here as well.\n",
     1)

id(str) { return str=="viewscreen"||str=="screen"||str=="door"
                 || str=="vault"; }
