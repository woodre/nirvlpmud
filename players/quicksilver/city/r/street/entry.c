#include "/players/quicksilver/city/include/std.h"

inherit ROOM;

reset(arg) {
	short_desc = "Edge of a city";
	long_desc = 
"\tYou appear to be at the edge of a city.\n" +
"\tBehind you, a blue portal leads somewhere entirely different.  An old beat-up\n" +
"sign indicates that this stretch of asphalt is known as \"Well Way.\"  The only\n" +
"direction worth traversing appears to be south.\n";
	dest_dir = ({ ROOM_DIR + "street/well_come", "south" });
	set_light(1);
}