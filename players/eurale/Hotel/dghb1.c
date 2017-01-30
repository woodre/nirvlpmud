#include "defs.h"
inherit "room/room";

reset(arg) {

if(!present("joseph")) {
  move_object(clone_object("players/eurale/Hotel/NPC/joseph"),TO); }

  if(arg) return;
set_light(0);

short_desc = "Drygulch Hotel basement";
long_desc =
	"  You descend the creaking stairs to the bottom.  You stand at \n"+
	"the base of the stairs on a dirt floor.  You can barely make out \n"+
	"the beams overhead that are supporting the hotel and you sense \n"+
	"movement near them.  There are doorways that lead to different \n"+
	"sections of the basement. \n";

items = ({
	"floor","A dusty, red-clay mixture... very dry to the touch",
	"beams","Large sturdy, wooden beams with hundreds of bats hanging \n"+
		"from them, like a fur covering",
	"doorways","It is too dark to see in from here",
});

dest_dir = ({
	"/players/eurale/Hotel/dghb5.c","east",
	"/players/eurale/Hotel/dghb3.c","west",
	"/players/eurale/Hotel/dghb2.c","south",
	"/players/eurale/Hotel/dgh3.c","up",
});

}
