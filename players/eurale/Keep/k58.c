#include "/players/eurale/defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
if(!present("centaur")) {
move_object(clone_object("players/eurale/Keep/NPC/wendle"),TO); }
set_light(1);

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"  The tunnel into this lovely canyon is far off to the east.\n"+
	"The sheer rock walls are still visible all around you but they\n"+
	"only enhance the beauty of this place.  The swaying grasses \n"+
	"and lush trees make this a serene and peaceful spot.\n";

items = ({
	"walls","Sheer sheets of rock, straight up",
	"grasses","Long, green, marsh grasses waving in the breeze",
	"trees","Small, leafy trees in thick groves",
});

dest_dir = ({
	"players/eurale/Keep/k57.c","north",
	"players/eurale/Keep/k59.c","south",
	"players/eurale/Keep/k55.c","east",
});

}
