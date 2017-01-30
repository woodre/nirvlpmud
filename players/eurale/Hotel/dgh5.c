#include "defs.h"
inherit "room/room";

reset(arg) {

if(!present("bill")) {
  move_object(clone_object("players/eurale/Hotel/NPC/buffbill"),TO); }

  if(arg) return;
set_light(1);

short_desc = "Drygulch Hotel dining room";
long_desc =
	"  This is the hotel dining room.  In the center of the room \n"+
	"is a long table with chairs surrounding it.  The room is well \n"+
	"lit from the windows facing south and east.  There is a large \n"+
	"bowl and pitcher sitting on another smaller table against the \n"+
	"south wall. \n";

items = ({
	"table","A long clean table that will seat many guests.  It \n"+
		"looks as if it is ready for the next meal",
	"chairs","Straight-backed wooden chairs",
	"south window","You can see past the edge of town into the \n"+
		"desert beyond... a beautiful view",
	"east window","The edge of another building to the northeast \n"+
		"partially blocks the view of the desert beyond",
	"pitcher","A pitcher full of water to wash with after a \n"+
		"delicious home-cooked meal",
	"bowl","A large earthenware bowl for washing",
});

dest_dir = ({
	"/players/eurale/Hotel/dgh3.c","west",
});

}
