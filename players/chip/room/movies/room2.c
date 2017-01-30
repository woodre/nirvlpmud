/*
*      Function:
*      Change History:
*      Chip (C) 2007
*/
#include <ansi.h>
inherit "/room/room";

int dead;

reset(arg)
{
::reset(arg);

if(arg) return;

set_light(1);

dead = 0;

short_desc = ""+MAG+"A strange underground pyramid"+NORM+"";

long_desc =
	"The sacrificial chamber is here, and there are surrounding remnants\n"+
	"of former cattle, which humans were used as by the "+GRN+"Aliens"+NORM+" who are\n"+
	"at war with the Predators. You now have to make a decision... pick\n"+
	"a side and fight for your life or try and turn back before they find\n"+
	"you. There is one open door, on the opposite side of the room.\n";

add_listen("war", "The sounds of a fierce battle fill your ears from all directions.");
move_object(clone_object("/players/chip/mobs/movies/alien.c"));
items =
({
	"chamber",
	"A large round room with tables forming a circle. At the end of each\n"+
	"table is a round platform holding what looks to be an egg of some kind",
	"remnants",
	"Skeletons (and some flesh) hang from the walls and one is on each\n"+
	"sacrifice table. Looks like something broke OUT of the chest cavity",
	"cavity",
	"Something forced its way out of the chests of these people",
	"chest cavity",
	"Something forced its way out of the chests of these people",
	"cattle",
	"Skeletons (and some flesh) hang from the walls and one is on each\n"+
	"sacrifice table. Looks like something broke OUT of the chest cavity",
	"tables",
	"Solid stone tables made to hold the bodies of the sacrificed",
	"egg",
	"It looks to be an alien egg. You can see a facehugger moving inside",
	"door",
	"Through the door you can see a stone footbridge",
	"footbridge",
	"A small stone footbridge, possibly leading to another room",
	"skeletons",
	"The skeletal remains of many expendable humans",
	});

dest_dir =
({
	"/players/chip/room/movies/room4.c",     "southeast",
	"/players/chip/room/movies/room3.c",     "cross_bridge",
	});
		
}
void init(){::init();add_action("cmd_search", "search");}
status cmd_search(string str){
if(!str){
write("Maybe you shouldn't...\n");
return 1;
}
if(str == "egg" && dead){
write("The egg is already open and empty.\n");
return 1;
}
if(str == "egg" && !dead){
write("Out of nowhere, a facehugger bursts out of the egg and attempts to attach to your face!\n");
move_object(clone_object("/players/chip/mobs/movies/facehugger.c"), this_object());
dead = 1;
return 1;
}
}
