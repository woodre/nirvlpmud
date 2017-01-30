#include "defs.h"
inherit "room/room";

reset(arg) {

if(!present("john")) {
  move_object(clone_object("players/eurale/Hotel/NPC/fremont"),TO); }

  if(arg) return;
set_light(1);

short_desc = "Drygulch Hotel kitchen";
long_desc =
	"  You have entered the hotel kitchen.  The smell of fresh cooking \n"+
	"still lingers in the air.  There is a large counter with a sink \n"+
	"and taking up a majority of the room is a huge pot-bellied, cast \n"+
	"iron wood burning stove.  There are also many pots hanging along \n"+
	"the walls and a pump off to the side of the sink. \n";

items = ({
	"counter","A sturdy counter attached to the walls where dinner \n"+
		"ingredients can be cut and chopped",
	"sink","A large, deep, cast iron sink",
	"stove","A huge stove with lots of cooking area on top and a very\n"+
		"large oven for baking",
	"pots","Cast iron pots of different sizes and depths",
	"pump","A hand pump for drawing water from the well far below",
});

dest_dir = ({
	"/players/eurale/Hotel/dgh3.c","east",
});

}
