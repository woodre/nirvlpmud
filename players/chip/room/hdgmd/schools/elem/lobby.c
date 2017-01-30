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

short_desc = "Main Lobby of HdG Elementary";

long_desc =
	"This is the main lobby and entryway of Havre de Grace Elementary school. You hear\n"+
	"the faint sound of voices coming from the hallways to the east and north. There are\n"+
	"drawings and photos of young children smiling in classrooms displayed in a glass\n"+
	"case. There is also a door to the west, and a set of doubledoors to the southwest.\n"+
	"The floor looks to be freshly swept and mopped.\n";

add_listen("voices", "You hear what seems to be mixed sounds of children and adults talking from all around");

items =
({
	"case",
	"There are pictures of the kids in some of the classrooms as well as\n"+
	"some of the drawings they have done so well",
	"door",
	"There is a sign on the door. It is unlocked",
	"sign",
	"The sign reads "+HIY+"Main Office"+NORM+"",
	"doubledoors",
	"The doors are open, there is a banner above them",
	"banner",
	"The banner reads "+HIY+"School Library"+NORM+"",
	"floor",
	"It is nice and clean, as if it had just been swept and mopped",
	"photos",
	"Photographs of children in their classrooms, seeming to enjoy themselves",
	"drawings",
	"Several sketches and paintings created by some of the students here",
	});

dest_dir =
({
	"/players/chip/room/hdgmd/schools/elem/office.c",     "office",
	"/players/chip/room/hdgmd/schools/elem/library1.c",     "southwest",
	"/players/chip/room/hdgmd/schools/elem/westhall1.c",     "north",
	"/players/chip/room/hdgmd/schools/elem/easthall1.c",     "east",
	});

}