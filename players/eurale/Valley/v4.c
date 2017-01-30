/*  The Park Valley  */

#include "defs.h"
inherit "room/room";

reset(arg) {

if(!present("pteranodon")) {
  move_object(clone_object("players/eurale/Park/NPC/pter"),TO); }

  if(arg) return;
set_light(1);

short_desc = "Hidden valley";
long_desc =
	"  Carefully choosing your handholds and footholds, you climb \n"+
	"to the top of this huge boulder.  There is a large, crude- \n"+
	"looking arrangment of sticks and leaves piled together. You \n"+
	"can see off above the forest in nearly every direction but \n"+
	"the edge of the valley is still high above you. \n";

items = ({
	"arrangement","This appears to be the nest of a pteranodon",
});

dest_dir = ({
	"players/eurale/Valley/v5.c","down",
});

}
realm() { return "NT"; }
