inherit "/room/room";
#include <ansi.h>
#include "../../defs.h"

reset(arg)
{
::reset(arg);

if(!present("rogueboard")) {
        move_object(clone_object(HALLOBJ+"board.c"),this_object());
}

if(arg) return;
	set_light(1);
	short_desc = HIK+"A Dark Corridor"+NORM;
	long_desc =
	"A small, deep, dark cave where the darkness seems to go\n"+
	"on forever. An eerie, cold wind gushes from the back of\n"+
	"the cave. The dungeon walls are covered in thick spider\n"+
	"webs with dust blowing around. Other rogues walk from room\n"+
	"to room yet leave no sign of footsteps.\n";

items =

({
	"darkness",
	"Complete and utter darkness",
	"walls",
	"Large spider webs are caked onto the walls",
	"rogues",
	"Your fellow members of the Brotherhood",
	"cave",
	"Dark, moist rocks form this cave",
	"webs",
	"Thick spider webs catch specks of dust flying in the wind",
	"dust",
	"Large dust bunnies tumble across the ground",
	"rocks",
	"Old, jagged rocks set perfectly on top of each other",
	"ground",
	"The ground is moist and wet from the moisture"
	});

dest_dir =
({
	HALLRMS+"store.c",	"east",
	HALLRMS+"pub.c", "west",
	HALLRMS+"poison.c", "north",
	"/players/shinshi/entrancehall.c", "leave",
	});
}

realm(){ return "NT"; }
query_no_fight(){ return 1; }