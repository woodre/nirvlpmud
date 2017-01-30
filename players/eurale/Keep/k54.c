#include "/players/eurale/defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
if(!present("dwarf")) {
move_object(clone_object("players/eurale/Keep/NPC/hylar"),TO); }
set_light(1);

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"  You have managed to hike your way up this outcropping of rock\n"+
	"to a hidden little place.  It is one of nature's phenomenon with\n"+
  "a small trickling stream of fresh water bubbling up out of a small\n"+
	"crack in the rock.\n";

items = ({
	"place","A flat opening hidden in the rocks and well protected",
	"stream","Clear, cold and continuously running",
});

dest_dir = ({
	"players/eurale/Keep/k55.c","hike",
});

}
