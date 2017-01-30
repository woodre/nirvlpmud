#include "DEFS.h"
inherit "room/room";

reset(arg) {

if(!present("dopey")) {
  move_object(clone_object("players/eurale/Dis/SnWht/NPC/dopey"),TO); }

  if(arg) return;
set_light(1);

short_desc = "Woodland cottage";
long_desc =
	"  You are standing in the living room of the cozy cottage.  There \n"+
	"are chairs scattered about and a long bench against the wall.  There\n"+
	"is a small stairwell leading down to the north and other rooms \n"+
	"farther back in the building.\n";

items = ({
	"room","The room is clean, airy and nicely arranged",
	"chairs","Various sizes and materials make up these miniature\n"+
		"sitting spots",
	"bench","A long wooden bench made from split logs",
});

dest_dir = ({
	"players/eurale/Dis/SnWht/dmd19.c","north",
	"players/eurale/Dis/SnWht/dmd23.c","southeast",
	"players/eurale/Dis/SnWht/dmd21.c","south",
	"players/eurale/Dis/SnWht/dmd13.c","out",
});

}
