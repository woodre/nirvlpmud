inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(!present("shinshi_lip_mob")) {
	move_object(clone_object("/players/shinshi/areas/coining/mobs/studentlip.c"), this_object());
}

if(arg) return;
	set_light(1);
	short_desc = "A small hallway";
	long_desc =
		"This long hallway has colorful pictures taped all over the walls.\n"+
		"There are window-less wooden doors on either side of the hall.\n"+
		"Small silhouettes have been painted on each door.  The floor is\n"+
		"polished, but here and there a scuff mark has resisted even the\n"+
		"most vigorous cleaning attempts.\n";

items =

({
	"pictures", "Many different pictures are taped to the walls",
	"walls", "Plain white walls surround you",
	"doors", "Doors leading into different rooms",
	"silhouettes", "The silhouettes are one of a person in pants and one of a person in a dress",
	"door", "Doors leading into different rooms",
	"floor", "The floor glistens and sparkles",
	"scuff", "A tough mark on the floor refuses to come up",
	"scuff mark", "A tough mark on the floor refuses to come up",
	"mark", "A tough mark on the floor refuses to come up",
});

dest_dir =
({
	"/players/shinshi/areas/coining/rooms/rm7.c",	"west",
	"/players/shinshi/areas/coining/rooms/rm4.c",	"north",
	"/players/shinshi/areas/coining/rooms/rm2.c",	"south",
	"/players/shinshi/areas/coining/rooms/rm8.c",	"east",
});
}
