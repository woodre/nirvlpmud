/*  The Park Valley  */

#include "defs.h"
inherit "room/room";

reset(arg) {

if(!present("brontosaurus")) {
  move_object(clone_object("players/eurale/Park/NPC/bronto"),TO); }

  if(arg) return;
set_light(1);

short_desc = "Hidden valley";
long_desc =
	"  You stand on the shore of a huge lake.  The sand is very \n"+
	"coarse and dark.  The water is almost green as it reflects the \n"+
	"vegetation that surrounds the lake.  There are tracks all along \n"+
	"the water's edge. \n";

items = ({
	"water","The water is murky and teaming with life, small creatures \n"+
		"that swim about constantly",
	"tracks","The tracks vary from small to large and overlap one \n"+
		"another from all the animals that come to lake to drink",
	"sand","This coarse, dark sand looks almost like volcanic cinders",
});

dest_dir = ({
	"players/eurale/Valley/v15.c","north",
	"players/eurale/Valley/v14.c","northwest",
	"players/eurale/Valley/v29.c","west",
});

}
realm() { return "NT"; }
