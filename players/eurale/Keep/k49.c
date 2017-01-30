#include "/players/eurale/defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
if(!present("imp")) {
move_object(clone_object("players/eurale/Keep/NPC/sea_imp"),TO); }
set_light(1);

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"  You have climbed out of the murky water into a small cove,\n"+
	"hidden from the rest of the cavern.  The floor of the cove is\n"+
	"covered with rotting kelp and seaweed.\n";

items = ({
	"kelp","Ocean vegetation",
	"seaweed","Long green and brown weeds",
});

dest_dir = ({
	"players/eurale/Keep/k39.c","water",
});

}
