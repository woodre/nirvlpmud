#include "/players/quicksilver/city/include/std.h"

inherit ROOM;

reset(arg) {
	short_desc = "Well Way and Come Drive";
	long_desc = \
"\tThings are a bit more up-beat here.  This is an intersection, albeit not a\n" +
"particularly busy one.\n" +
"\tThe road signage, which is an unusual combination of neon and Braille (you can\n" +
"read Braille, obviously), lets you know that \"Come Drive\" begins to the east.\n";
	dest_dir = ({ \
		ROOM_DIR + "street/entry", "north",
		ROOM_DIR + "street/come", "east" });
	set_light(1);
}