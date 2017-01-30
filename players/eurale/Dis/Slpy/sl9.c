#include "DEFS.h"
inherit "room/room";

reset(arg) {

if(!present("ichabod")) {
  move_object(clone_object("players/eurale/Dis/Slpy/NPC/ich"),TO); }

  if(arg) return;
set_light(1);

short_desc = "Sleepy Hollow Schoolhouse";
long_desc =
	"  This is the schoolhouse of Sleepy Hollow.  There are about\n"+
	"15 desks in this single room.  There is a fireplace behind the\n"+
	"teacher's desk and a chalk board on the side wall.\n";

items = ({
	"desks","Small chairs with side rests and a writing surface",
	"fireplace","A stone fireplace to warm the building",
	"desk","An oversize wooden desk with 2 side drawers",
});

dest_dir = ({
	"players/eurale/Dis/Slpy/sl10.c","exit",
});

}
