#include "DEFS.h"
inherit "room/room";

reset(arg) {

if(!present("prince")) {
  move_object(clone_object("players/eurale/Dis/rooms/NPC/prince"),TO); }

  if(arg) return;
set_light(1);

short_desc = "Royal Palace";
long_desc =
	"  This is the grand hall of the Royal Palace.  The wine-colored \n"+
	"tapestry that covers the stone walls is embroidered with the \n"+
	"crest of the nobility.  The cut-glass windows refract the light\n"+
	"causing rainbows to appear on the granite floor.  The huge \n"+
	"chandelier with it's scores of candles lights the area with \n"+
	"shimmering luminescence.\n";

items = ({
	"tapestry","Beautifully woven with gold threaded embroidery",
	"windows","Beveled glass, brought from finest craftsmen",
	"chandelier","Cut glass crystals and formed copper, a magnificent\n"+
		"sight to behold",
});

dest_dir = ({
	"players/eurale/Dis/rooms/ml9.c","leave",
});

}
