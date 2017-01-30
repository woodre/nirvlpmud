#include "DEFS.h"
inherit "room/room";

reset(arg) {

if(!present("figaro")) {
  move_object(clone_object("players/eurale/Dis/Pino/NPC/fig"),TO); }

  if(arg) return;
set_light(1);

short_desc = "Geppetto's";
long_desc =
	"  This is the shop of Geppetto the woodcarver.  There are items\n"+
	"on display for sale.  The place is neat and tidy and you can see\n"+
	"through a doorway to the rear of the building.\n";

items = ({
	"items","Fantastic clocks, music boxes and every kind of toy you\n"+
		"can imagine.... each a work of art",
	"doorway","Looks like the workroom",
});

dest_dir = ({
	"players/eurale/Dis/Pino/twt16.c","leave",
	"players/eurale/Dis/Pino/twt18.c","back",
});

}
