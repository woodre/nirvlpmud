#include "/room/std.h"

#undef EXTRA_LONG
#define EXTRA_LONG\
    if (str == "table" || str == "stone table") {\
	write("You see nothing special about it.\n");\
	return;\
    }

TWO_EXIT("/players/doctor/CASTLE/tunnel4", "south",
	 "/players/doctor/CASTLE/tunnel_room", "north",
	 "Generic stone table",
	 "In a generic tunnel.\n" +
	 "There is a big generic stone table here.\n", 0)

id(str) {
    return str == "table" || str == "stone table";
}
