/*  Drygulch stable  */

#include "defs.h"
inherit "room/room";

reset(arg) {

if(!present("owner")) {
move_object(clone_object("players/eurale/Stable/NPC/owner"),TO); }

  if(arg) return;
set_light(1);

short_desc = "Drygulch Stable";
long_desc =
	"  You are standing in one of the horse stalls.  There is hay \n"+
	"piled up for feed and rings on each side of the opening.  The \n"+
	"stall is clean and there is a large bucket in the corner.  A \n"+
	"beautiful horse is tethered to the stall wall. \n";

items = ({
	"rings","Metal rings mounted to the wooden sides of the stall \n"+
		"to tie the horses to",
	"bucket","A wooden bucket holding water",
	"horse","A buckskin colored gelding.  It has some scars on it's \n"+
		"hind quarters, maybe from a whip",
});

dest_dir = ({
	"/players/eurale/Stable/sta4.c","east",
});

}
