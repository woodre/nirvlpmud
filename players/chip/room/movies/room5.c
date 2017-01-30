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

short_desc = ""+HIK+"Musty Cellar"+NORM+"";

long_desc =
	"You suddenly find yourself in a dark and musty basement. There are\n"+
	"little skittering sounds all around you, but it's hard to tell what\n"+
	"is making them. There's some cardboard boxes in the far corner and\n"+
	"a large chest in the middle of the floor. There are also 3 posts\n"+
	"that go from the floor to the ceiling for support.\n";

add_smell("air", "Musty....just as most basements are.");    
add_listen("sounds", "Sounds like maybe a bunch of bugs.....what is that?");
items =
({
	"basement",
	"It's dark, and hard to see. There's an unusually large hole in\n"+
	"the corner of the floor",
	"boxes",
	"They are all open and unfortunately, empty",
	"chest",
	"A very old oak chest, with designs inlaid in gold. As you look\n"+
	"closer, you see a unique looking lock, which is keeping it closed",
	"lock",
	"It looks to be made of platinum, and has a Celtic cross finely\n"+
	"etched into the face of it",
	"posts",
	"Three long 4x4s that keep the first floor from coming down into the cellar",
	"hole",
	"A deep, dark hole. Perhaps if you reach in you might find some treasure",
	"cross",
	"This is the original Celtic cross, and has been etched into the front of\n"+
	"the lock on the chest",
	});

dest_dir =
({
	"/players/chip/room/movies/room6.c",     "east",
	"/players/chip/room/movies/room4.c",     "northeast",
	"/players/chip/room/movies/room8.c",     "southeast",
	});
		
}
void init(){::init();add_action("cmd_search", "search");}
status cmd_search(string str){
if(!str){
write("Your skin begins to crawl a bit, for no apparent reason.\n");
return 1;
}
if(str == "hole" && dead){
write("There is nothing to find here, other than what can be immediately seen.\n");
return 1;
}
if(str == "hole" && !dead){
write("An entire horde of large black spiders rushes forth from the hole, overtaking you!\n");
move_object(clone_object("/players/chip/mobs/movies/spiders.c"), this_object());
dead = 1;
return 1;
}
}
