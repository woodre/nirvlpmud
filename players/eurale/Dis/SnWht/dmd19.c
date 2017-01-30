#include "DEFS.h"
inherit "room/room";

reset(arg) {

if(!present("sleepy")) {
  move_object(clone_object("players/eurale/Dis/SnWht/NPC/sleepy"),TO); }

  if(arg) return;
set_light(1);

short_desc = "Woodland cottage";
long_desc =
	"  You squeeze through the small doorway and follow the stairway\n"+
	"down to a sleeping room.  There are 7 neatly made beds lining the\n"+
	"the walls.\n";

items = ({
	"beds","Short beds with wooden frames... all perfectly made \n"+
		"with wool blankets and tucked nicely",
});

dest_dir = ({
	"players/eurale/Dis/SnWht/dmd20.c","up",
});

}
