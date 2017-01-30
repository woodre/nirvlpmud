inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(!present("shinshi_key_mob")) {
	move_object(clone_object("/players/shinshi/areas/coining/mobs/studentkey.c"),this_object());
}
if(!present("shinshi_lip_mob")) {
	move_object(clone_object("/players/shinshi/areas/coining/mobs/studentlip.c"),this_object());
}	
	
if(arg) return;
	set_light(1);
	short_desc = "A small hallway";
	long_desc =
		"This long hallway has colorful pictures taped all over the walls.\n"+
		"There is a set of glass doors at this end of the hall that appear\n"+
		"to lead to a lobby.  On either side of the hallway there are\n"+
		"smaller, wooden doors with windows in them.  The floor is polished,\n"+
		"but here and there a scuff mark has resisted even the most vigorous\n"+
		"cleaning attempts.\n";

items =

({
	"pictures", "Many different pictures are taped to the walls",
	"walls", "Plain white walls surround you",
	"doors", "Large glass doors",
	"glass doors", "Large glass doors make an exit to the lobby",
	"lobby", "The lobby leads to an exit",
	"wooden doors", "Doors leading into different rooms",
	"windows", "Small windows are built into the top of the door",
	"floor", "The floor glistens and sparkles",
	"scuff", "A tough mark on the floor refuses to come up",
	"scuff mark", "A tough mark on the floor refuses to come up",
	"mark", "A tough mark on the floor refuses to come up",
});

dest_dir =
({
	"/players/shinshi/areas/coining/rooms/rm1.c", "south",
	"/players/shinshi/areas/coining/rooms/rm3.c", "north",
	"/players/shinshi/areas/coining/rooms/rm5.c", "west",
	"/players/shinshi/areas/coining/rooms/rm6.c", "east",
});
}
