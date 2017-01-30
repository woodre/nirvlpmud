#include "DEFS.h"
inherit "room/room";

reset(arg) {

if(!present("foulfellow")) {
  move_object(clone_object("players/eurale/Dis/Pino/NPC/foul"),TO); }
if(!present("gideon")) {
  move_object(clone_object("players/eurale/Dis/Pino/NPC/gid"),TO); }

  if(arg) return;
set_light(1);

short_desc = "Timberwood Trail";
long_desc =
	"  As you make the turn, the road seems to come to an end.  The \n"+
	"surrounding berry bushes provide a hideaway to stop and rest\n"+
	"and get your bearings.  The drifting clouds float by and the \n"+
	"blue sky goes on endlessly.\n";

items = ({
	"bushes","A blueberry bush",
	"road","A dirt road",
	"clouds","That one looks like a shark",
});

dest_dir = ({
	"players/eurale/Dis/Pino/twt20.c","east",
});

}
