#include "/players/eurale/defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
if(!present("ghaggler")) {
move_object(clone_object("/players/eurale/Keep/NPC/ghaggler"),TO); }
set_light(1);

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"  This is a very well camouflaged shelf just higher than the\n"+
	"the water level of the swamp.  It provides easy access from and\n"+
	"to the water.  It is deep enough to hide from view of the swamp\n"+
	"and the surrounding shores.\n";

items = ({
});

dest_dir = ({
	"players/eurale/Keep/k42.c","water",
});

}
