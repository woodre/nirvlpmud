/*
*      Function:
*      Change History:
*/
#include <ansi.h>
inherit "/room/room";

reset(arg)
{
::reset(arg);

if(arg) return;

set_light(1);

short_desc = ""+GRN+"A fairly empty lobby area"+NORM+"";

long_desc =
	"There is an old counter here, which is long and displays many snack\n"+
	"items. Unfortunately there is no one around who seems to work here.\n"+
	"There are other customers around who seem to be just as confused as\n"+
	"you are about the lack of service. Perhaps the employees all ran off\n"+
	"in fear for their lives from the creatures that are loose. Or were\n"+
	"killed by them...\n";

add_smell("air", "Stale popcorn and fresh blood. What a mix.");

move_object(clone_object("/players/chip/mobs/movies/customer.c"));
move_object(clone_object("/players/chip/mobs/movies/customer.c"));
move_object(clone_object("/players/chip/mobs/movies/customer.c"));
move_object(clone_object("/players/chip/mobs/movies/customer.c"));
move_object(clone_object("/players/chip/mobs/movies/customer.c"));

items =
({
	"counter",
	"It is quite long, and has several cash registers lining it, which are\n"+
	"sadly empty. There are many snacks displayed but none look very good now.\n"+
	"Something about the popcorn machine catches your eye...",
	"snacks",
	"Most are either extremely stale or have blood stains on the boxes",
	"registers",
	"Fairly old cash registers which are very empty, unfortunately",
	"machine",
	"This old popcorn machine seems to be filled with not only old, very\n"+
	"stale popcorn, but also lots of severed fingers and toes..",
	});

dest_dir =
({
	"/players/chip/room/movies/room8.c",     "southwest",
	"/players/chip/room/movies/mroom.c",     "northeast",
	"/players/chip/room/movies/wroom.c",     "east",
	"/players/chip/room/movies/room4.c",     "northwest",
	"/players/chip/room/movies/room6.c",     "west",
	});
		
}