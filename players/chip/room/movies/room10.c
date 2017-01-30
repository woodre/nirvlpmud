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

short_desc = ""+GRN+"A hallway"+NORM+"";

long_desc =
	"This is the hallway in the second section of Nirvana Cinemas. There are\n"+
	"doors to the west and east, and the hallway continues to the south. You\n"+
	"see a few customers here frantically running in circles screaming. The\n"+
	"sounds of violence and pain are all around you, and once again you feel\n"+
	"extremely uneasy....actually scared. There are what used to be lit signs\n"+
	"on each side of the hall way. There is a heavily barred doorway to the\n"+
	"north that has been welded shut.\n";

add_smell("air", "Mmmm, the scent of gore!");
add_listen("sounds", "The sounds of agonizing screams and demonic cackles fill your ears.");

move_object(clone_object("/players/chip/mobs/movies/customer.c"));
move_object(clone_object("/players/chip/mobs/movies/customer.c"));
move_object(clone_object("/players/chip/mobs/movies/customer.c"));

items =
({
	"hallway",
	"The second section of the theater is accessible from this hallway',
	"doors",
	"One leads west, the other east, into showing rooms",
	"signs",
	"They used to be brightly lit and show what movies were being shown",
	"doorway",
	"The doorway is barred up and welded completely shut",
	});

dest_dir =
({
	"/players/chip/room/movies/room11.c",     "west",
	"/players/chip/room/movies/room12.c",     "east",
	"/players/chip/room/movies/room13.c",     "south",
	});
		
}