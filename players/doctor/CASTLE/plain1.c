#include "/room/room.h"
object wolf;

#undef EXTRA_RESET
#define EXTRA_RESET\
    if (!wolf) {\
	wolf = clone_object("obj/monster");\
	call_other(wolf, "set_name", "wolf");\
	call_other(wolf, "set_level", 3);\
	call_other(wolf, "set_short", "A generic creature wearing a T-shirt that reads WOLF");\
	call_other(wolf, "set_wc", 7);\
	call_other(wolf, "set_move_at_reset");\
	call_other(wolf, "set_whimpy");\
	move_object(wolf, "/players/doctor/CASTLE/ruin");\
    }

TWO_EXIT("/players/doctor/CASTLE/clearing", "south",
	 "/players/doctor/CASTLE/plain2", "north",
	 "A large open generic plain",
	 "A large open generic plain, extending to north and south.\n", 1)
