#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    if (!arg) {\
	 move_object(clone_object("players/boltar/templar/items/sponsorboard"), this_object()); \
    }

ONE_EXIT("players/boltar/templar/adv_guild", "down",
	 "The sponsor room of Templars ",
"This small room at the top of the stairs is where prospective\n"+
"members are listed for entry into the guild. The walls are of\n"+
"simple wood paneling, the floor simple wood planks which creek\n"+
"as one walks upon them. There is very little light, barely enough\n"+
"to read.\n",1)
query_board() {
return present("board",this_object());
}
