#include "/players/eurale/closed/ansi.h"
#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"  You have come to the edge of a large underground swamp of some\n"+
	"kind.  The huge cavern that rises above it has small holes in\n"+
	"the ceiling that allows just enough light in to see and sustain\n"+
	"some minor plant growth.  The water is dark and murky.\n";

items = ({
	"water","Dark brownish-green, you can't see through it",
	"holes","Small holes that open to the outside but much too high\n"+
		"to see clearly",
	"cavern","A large bubble in this huge stone.  It has relatively\n"+
		"smooth sides and extends farther than you can see",
});

dest_dir = ({
	"players/eurale/Keep/k36.c","north",
	"players/eurale/Keep/k38.c","south",
	"players/eurale/Keep/k39.c","west",
});

}
