inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(!present("shinshi_key_mob")) {
	move_object(clone_object("/players/shinshi/areas/coining/mobs/studentkey.c"),this_object());
}

if(arg) return;
	set_light(1);
	short_desc = "The Sandbox";
	long_desc =
		"There is a sandbox just outside the door of the preschool.  Nine\n"+
		"pails and nine shovels lay scattered around in the sand.  There\n"+
		"are also various action figures and toy cars, wheels clogged with\n"+
		"sand.  Other playground equipment can be seen in the distance.\n";
items =

({
	"shovels",
	"Light blue plastic shovels used for digging into the sandbox",
	"pails",
	"Bright yellow pails allow you to keep different items such as sand in it",
	"figures",
	"Action figures such as Superman, Batman, and Spiderman lie here in the sand",
	"cars",
	"A couple of Hot Wheels cars lie in the sand, idle",
	"toy cars",
	"A couple of Hot Wheels cars lie in the sand, idle",
	"preschool",
	"A smaller building with windows all around it and doors leading inside",
	"sand",
	"The sand glistens in the sun",
	"wheels",
	"The wheels have chunks of sand stuck on them",
	"door",
	"A large glass door that allows someone in and out of the building",
	"sandbox",
	"A large sandbox that holds sand in it",
	"equipment",
	"Equipment such as a slide, a sandbox, etc. are in the distance",
	"slide",
	"A large slide",
});

dest_dir =
({
	"/players/shinshi/areas/coining/rooms/rm4.c",	"back",
	"/players/shinshi/areas/coining/rooms/outside2.c",	"east",
});
}
