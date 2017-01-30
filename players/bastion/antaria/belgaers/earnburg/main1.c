
#include "std.h"

#undef EXTRA_INIT
#define EXTRA_INIT extra_init();

extra_init() {
     add_action("north", "north");
}


FOUR_EXIT("players/bastion/antaria/belgaers/road5", "north",
     "players/bastion/antaria/belgaers/earnburg/shop1", "east",
     "players/bastion/antaria/belgaers/earnburg/shop2", "west",
     "players/bastion/antaria/belgaers/earnburg/main2", "south",
     "Main Street",
     "You enter a busy, little town. The Main Street runs north to south\n"+
     "here, shops flanking either side. South you see a larger buiding.\n",
     1)

north() {
     if(this_player()->is_player()) {
          write("You leave the town and head back to the road...\n");
          return 0; }
     return 1;
}
