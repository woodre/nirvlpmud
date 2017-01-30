/* a higher level cave  */

#include "defs.h"
inherit "room/room";

reset(arg) {

if(!present("wolf 1")) {
  move_object(clone_object("players/eurale/Cave/NPC/wolf1"),TO); }
if(!present("wolf 2")) {
  move_object(clone_object("players/eurale/Cave/NPC/wolf2"),TO); }

  if(arg) return;
set_light(0);

short_desc = "a dark cave";
long_desc =
	"  You stand in a carved out tunnel through the rocks.  The air \n"+
	"is cool and smells fairly musty like there isn't much movement \n"+
	"inside the cave.  The darkness is penetrating and you can just \n"+
	"make out the sides of the tunnel as you inch along.  Your foot- \n"+
	"steps echo slightly as you walk.  There are bones scattered \n"+
	"about the area as well. \n";

items = ({
	"sides","The shadows make the sides of the cave appear and then \n"+
		"seem to disappear into the darkness",
	"bones","These look like human skeletal bones",
});

dest_dir = ({
	"/players/eurale/Cave/cav2.c","south",
	"/players/eurale/Cave/cav4.c","west",
});

}
