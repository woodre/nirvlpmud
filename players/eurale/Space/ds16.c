#include "DEFS.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
if(!present("elder")) {
  move_object(clone_object("players/eurale/Space/NPC/elder"),TO); }
set_light(0);

short_desc = "Deep Space";
long_desc =
  "  You crawl around the sharp turn and find yourself in a hollowed\n"+
  "out burrow of some kind.  There are scraps of indistinguishable\n"+
  "items partially buried in the "+RED+"red dirt"+NORM+".\n";

items = ({
	"dirt","Very fine and powdery",
	"scraps","Nothing you can make out",
});

dest_dir = ({
	"players/eurale/Space/ds15.c","east",
});

}
