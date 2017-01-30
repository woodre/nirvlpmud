#include "DEFS.h"
inherit "room/room";

reset(arg) {

if(!present("happy")) {
  move_object(clone_object("players/eurale/Dis/SnWht/NPC/happy"),TO); }

  if(arg) return;
set_light(1);

short_desc = "Woodland cottage";
long_desc =
	"  You pass under an archway and find yourself in the dining area\n"+
	"of the cottage.  There is a wide, long table with 7 small chairs\n"+
	"and one larger chair at the head of the table.  A small arrange-\n"+
	"ment has been placed in the center of the table.\n";

items = ({
	"table","A wood slab table, able to sit and feed at least eight",
	"chairs","Wooden chairs for dining",
	"arrangement","Flowers from the gardens around the cottage",
});

dest_dir = ({
	"players/eurale/Dis/SnWht/dmd20.c","north",
	"players/eurale/Dis/SnWht/dmd23.c","east",
});

}
