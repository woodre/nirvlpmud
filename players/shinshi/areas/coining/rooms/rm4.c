inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(arg) return;
	set_light(1);
	short_desc = "A small hallway";
	long_desc =
		"This long hallway has colorful pictures taped all over the walls.\n"+
		"There is a set of glass doors at this end of the hall that appear\n"+
		"to lead outside.  On one side of the hallway there is a smaller,\n"+
		"wooden door with a window in it.  There is a sign posted on the\n"+
		"wall next to the door.  The floor is polished, but here and there\n"+
		"a scuff mark has resisted even the most vigorous cleaning attempts.\n";

items =

({
	"pictures", "Many different pictures are taped to the walls",
	"walls", "Plain white walls surround you",
	"doors", "Which doors? Wooden or glass?",
	"glass doors", "Large glass doors make an exit to the outside",
	"lobby", "The lobby leads to an exit",
	"wooden door", "A door leading into a different room",
	"window", "A small window is built into the top of the door",
	"floor", "The floor glistens and sparkles",
	"scuff", "A tough mark on the floor refuses to come up",
	"scuff mark", "A tough mark on the floor refuses to come up",
	"mark", "A tough mark on the floor refuses to come up",
	"sign", "The sign reads, \"Teacher's Lounge\"",
});

dest_dir =
({
	"/players/shinshi/areas/coining/rooms/rm9.c", "west",
	"/players/shinshi/areas/coining/rooms/rm3.c", "south",
	"/players/shinshi/areas/coining/rooms/outside1.c", "outside",
});
}
