
#include "std.h"


FOUR_EXIT("players/bastion/antaria/belgaers/earnburg/main1", "north",
     "players/bastion/antaria/belgaers/earnburg/shop3", "east",
     "players/bastion/antaria/belgaers/earnburg/smithy", "west",
     "players/bastion/antaria/belgaers/earnburg/main3", "south",
     "Main Street",
     "You are walking down Main Street. Small shops stand on either\n"+
     "side of the road. A large building is to the south.\n",
     1)

north() {
     if(this_player()->is_player()) {
          write("You leave the town and head back to the road...\n");
          return 0; }
     return 1;
}
