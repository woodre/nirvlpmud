#include "DEFS.h"
inherit "room/room";

reset(arg) {

if(!present("pinocchio")) {
  move_object(clone_object("players/eurale/Dis/Pino/NPC/pino"),TO); }

  if(arg) return;
set_light(1);

short_desc = "Geppetto's";
long_desc =
	"  This is Geppetto's workroom.  There is a sturdy workbench with\n"+
	"tools upon it and chips of wood littering the floor.  Against the\n"+
	"wall are pieces of roughsawn log waiting to be turned into a\n"+
	"music box or toy for someone.\n";

items = ({
	"workbench","A thick wooden slab with a shelf underneath",
	"tools","Gouges, chisels and mallots of different sizes",
	"pieces","Ash, oak and walnut logs",
});

dest_dir = ({
	"players/eurale/Dis/Pino/twt17.c","front",
});
}
