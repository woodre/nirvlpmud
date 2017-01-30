/*
*      Function:
*      Change History:
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
	"This seems to be a preparation chamber for the Predators to ready\n"+
	"themselves for battle. There is a large sarcophagus in the center\n"+
	"of the room, and several weapons racks on the wall. There are the\n"+
	"remains of quite a few Aliens laying around, and the smell alone\n"+
	"from the decaying creatures is enough to sicken you.\n";
add_smell("air", "You almost vomit from the pungeant odor of rotting flesh.");
add_listen("war", "The sounds of a fierce battle fill your ears from all directions.");
move_object(clone_object("/players/chip/mobs/movies/predator.c"));
items =
({
	"chamber",
	"A large room with a sarcophagus in the center and some weapons racks\n"+
	"on the wall. There's also a footbridge leading off into the darkness",
	"remains",
	"The rotting corpses of more than a few Aliens",
	"bodies",
	"The rotting corpses of more than a few Aliens",
	"aliens",
	"The rotting corpses of more than a few Aliens",
	"sarcophagus",
	"You can't quite seem to get it open...perhaps try 'search'ing it",
	"racks",
	"These racks look to hold odd items that look sort of like razor edged\n"+
	"discs, retractable shuriken, extendable spears, and arm-mounted control\n"+
	"panels that contain retractable titanium claws",
	"wall",
	"It holds a weapons rack, as well as being covered in strange symbols",
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
	"discs",
	"Razor edged discs that the Predators use like killer frisbees",
	"shuriken",
	"Sharp retractable shuriken that can be thrown to impale a Predator's victim",
	"symbols",
	"They are strange and intricate, but you cannot decipher their meanings",
	"spears",
	"Short spears that can be extended during battle to better impale an opponent",
	"panels",
	"Arm-mountable control panels used for many operational purposes by the Predators\n"+
	"during their Alien hunt. They also have long metal claws that can be extended",
	});
dest_dir =
({
	"/players/chip/room/movies/room4.c",     "southwest",
	"/players/chip/room/movies/room2.c",     "cross_bridge",
	});
		
}
void init(){::init();add_action("cmd_search", "search");}
status cmd_search(string str){
if(!str){
write("You're too scared to find what you're looking for.\n");
return 1;
}
if(str == "sarcophagus" && dead){
write("Empty... it seems someone else got here first.\n");
return 1;
}
if(str == "sarcophagus" && !dead){
write("A second Predator approaches you sneakily from behind, then lets out a ROOOOOAAAR!\n");
move_object(clone_object("/players/chip/mobs/movies/predator2.c"), this_object());
dead = 1;
return 1;
}
}
