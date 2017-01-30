#include "DEFS.h"
inherit "room/room";

reset(arg) {

if(!present("crocodile")) {
  move_object(clone_object("players/eurale/Dis/Pan/NPC/croc"),TO); }

  if(arg) return;
set_light(1);

short_desc = "A Blue Lagoon";
long_desc =
	"  S P L A S H !  You jump off the ship into the blue lagoon.\n"+
	"The water is warm and clear and there are fish swimming in\n"+
	"abundance.  You've swum around under the stern of the ship \n"+
	"where it's shady and well hidden from above.\n";

items = ({
	"ship","The underside of the stern with the rudder pole",
	"fish","Beautiful fish of all colors",
});

dest_dir = ({
	"players/eurale/Dis/Pan/pc15.c","climb",
});

}
