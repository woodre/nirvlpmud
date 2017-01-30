#include "DEFS.h"
inherit "room/room";

reset(arg) {

if(!present("bashful")) {
  move_object(clone_object("players/eurale/Dis/SnWht/NPC/bashful"),TO); }

  if(arg) return;
set_light(0);

short_desc = "Diamond mine";
long_desc =
	"  You carefully edge your way through the tunnel and deeper into \n"+
	"the mine.  The air is stale and dank and the tunnel floor is wet\n"+
	"from some unknown water source.  There are streaks of minerals \n"+
	"running through the stone walls.  The tunnel continues to descend\n"+
	"deeper into the earth.";

items = ({
	"streaks","Various colors indicating different chemicals",
	"floor","Slippery rock from the moisture",
});

dest_dir = ({
	"players/eurale/Dis/SnWht/dmd18.c","down",
	"players/eurale/Dis/SnWht/dmd16.c","out",
});

}
