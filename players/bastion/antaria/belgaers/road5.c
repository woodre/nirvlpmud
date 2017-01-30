
#include "std.h"

#undef EXTRA_INIT
#define EXTRA_INIT extra_init();

extra_init() {
     add_action("south", "south");
}

THREE_EXIT("players/bastion/antaria/belgaers/road4", "east",
     "players/bastion/antaria/belgaers/earnburg/main1", "south",
     "players/bastion/antaria/belgaers/road6", "west",
     "Harrowers Way",
     "The road passes by a small town to the south. Smoke billows from\n"+
     "quiescent cottages, as villagers go about their daily rountine.\n",
     1)

south() {
     write("You enter the town...\n");
     if(this_player()->is_player()) return 0;
     return 1;
}
