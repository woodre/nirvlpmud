#include "/players/eurale/closed/ansi.h"
#define tpn this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"  You have walked out of the stone tunnel into an open space\n"+
	"of some size.  Although the stone walls extend upward for hun-\n"+
	"dreds of feet, you seem to be in a kind of bowl.  The sun shines\n"+
	"in and the area is lush with grasses and trees... all well pro-\n"+
	"tected from the outside by the steep cliffs.\n";

items = ({
	"walls","Sheer sheets of rock, straight up",
	"grasses","Long, green, marsh grasses waving in the breeze",
	"trees","Small, leafy trees in thick groves",
});

dest_dir = ({
	"players/eurale/Keep/k52.c","climb",
	"players/eurale/Keep/k53.c","south",
	"players/eurale/Keep/k2.c","east",
	"players/eurale/Keep/k55.c","west",
});

}
