#include "defs.h"
inherit "room/room";

reset(arg) {

if(!present("bill")) {
  move_object(clone_object("players/eurale/Hotel/NPC/pickett"),TO); }

  if(arg) return;
set_light(0);

short_desc = "Drygulch Hotel basement";
long_desc =
	"  The corner is filled with wooden racks.  There are various jars \n"+
	"of different sizes on the shelves.  There are also a number of \n"+
	"broken jars littering the floor around the rack. \n";

items = ({
	"racks","Wooden racks with lots of shelves to hold many jars",
	"jars","The jars contain items that have been put in them to preserve \n"+
		"their freshness for future use by the hotel",
});

dest_dir = ({
	"/players/eurale/Hotel/dghb1.c","west",
});

}
