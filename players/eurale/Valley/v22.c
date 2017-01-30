/*  The Park Valley  */

#include "defs.h"
inherit "room/room";

reset(arg) {

if(!present("stegosaurus")) {
  move_object(clone_object("players/eurale/Park/NPC/steg"),TO); }

  if(arg) return;
set_light(1);

short_desc = "Hidden valley";
long_desc =
	"  This is a flat, rocky area.  There are no trees in this area \n"+
	"because of all the stone.  Boulders of different sizes lay all \n"+
	"over.  You can see the treeline of the forest off in the distance.\n";

items = ({
	"boulders","Large, beautiful rocks with colors in them from the \n"+
		"minerals, no doubt",
});

dest_dir = ({
	"players/eurale/Valley/v23.c","east",
	"players/eurale/Valley/v8.c","northeast",
	"players/eurale/Valley/v7.c","north",
	"players/eurale/Valley/v6.c","northwest",
	"players/eurale/Valley/v21.c","west",
});

}
realm() { return "NT"; }
