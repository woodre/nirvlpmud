#include "/players/eurale/closed/ansi.h"
#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"  You are standing in the the thigh-deep swamp water.  The\n"+
	"bottom is soft and squishy, making moving hard.  The cavern\n"+
	"echoes the splashing you make as you move through the water.\n";

items = ({
	"water","Dark brownish-green, you can't see through it",
	"cavern","A large bubble in this huge stone.  It has relatively\n"+
		"smooth sides and extends farther than you can see",
});

dest_dir = ({
	"players/eurale/Keep/k40.c","north",
	"players/eurale/Keep/k44.c","west",
});

}
