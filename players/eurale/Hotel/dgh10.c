#include "defs.h"
inherit "room/room";

reset(arg) {

if(!present("charles")) {
  move_object(clone_object("players/eurale/Hotel/NPC/goodnight"),TO); }

  if(arg) return;
set_light(1);

short_desc = "Drygulch Hotel";
long_desc =
	"  This is one of the hotel guest rooms.  It has a bed, a small \n"+
	"table with a wash bowl, pitcher and lamp sitting on it and a \n"+
	"chair sitting next to the small window which provides light. \n"+
	"There is also a mirror hanging on the wall and a crucifix over \n"+
	"the bed. \n";

items = ({
	"bed","This comfortable looking bed is large and has a brass \n"+
		"headboard and footboard on it",
	"table","A small, wooden, four-legged table",
	"bowl","A white ceramic bowl for washing or shaving",
	"pitcher","A white ceramic pitcher for water",
	"lamp","A large oil lamp for evening light",
	"chair","A straight-backed wooden chair",
	"window","The small window provides a very limited view of the\n"+
		"surrounding city",
	"mirror","A large oval mirror with a wooden frame",
	"crucifix","A large, hand-carved, wooden crucifix",
});

dest_dir = ({
	"/players/eurale/Hotel/dgh9.c","east",
});

}
