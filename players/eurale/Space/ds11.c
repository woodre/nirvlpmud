#include "DEFS.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
if(!present("zodar")) {
  move_object(clone_object("players/eurale/Space/NPC/zodar"),TO); }
set_light(0);

short_desc = "Deep Space";
long_desc =
  "  You've crawled through a narrow tunnel to a carved out pocket\n"+
  "in the "+RED+"red crystal"+NORM+".  The walls sparkle and the floor is covered\n"+
  "with the remains of devoured prey\n";

items = ({
	"remains","Bones and rotting innards, left after the meal",
});

dest_dir = ({
	"players/eurale/Space/ds5.c","out",
});

}
