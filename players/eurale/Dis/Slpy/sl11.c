#include "DEFS.h"
inherit "room/room";

reset(arg) {

if(!present("boy")) {
  move_object(clone_object("players/eurale/Dis/Slpy/NPC/boy"),TO); }
if(!present("brom")) {
  move_object(clone_object("players/eurale/Dis/Slpy/NPC/brom"),TO); }

  if(arg) return;
set_light(1);

short_desc = "Ye Olde Schnapps Shoppe";
long_desc =
	"  This is the tavern of Sleepy Hollow.  It's a congregating\n"+
	"place for the men of town.  There is a bar and a long wooden\n"+
	"table which takes up most of the room.\n";

items = ({
	"bar","A long wooden bar where patrons can stand and drink their\n"+
		"ale at their liesure",
	"table","A table long enough to seat at least 20",
});

dest_dir = ({
	"players/eurale/Dis/Slpy/sl10.c","exit",
});

}
