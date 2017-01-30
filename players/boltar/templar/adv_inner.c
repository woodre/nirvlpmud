#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    if (!arg) {\
	 move_object(clone_object("players/boltar/templar/gcboard"), this_object()); \
    }

ONE_EXIT("players/boltar/templar/adv_guild", "north",
	 "The inner room of Templars ",
"  This is the inner chamber of the Knights.  Here discussions\n"+
"take place on the future of the guild and its members. There is\n"+
"a doorway leading north to the main hall of the knights.\n",1)
realm() { return "NT"; }
