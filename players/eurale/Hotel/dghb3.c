#include "defs.h"
inherit "room/room";

reset(arg) {

if(!present("bat")) {
  move_object(clone_object("players/eurale/Hotel/NPC/masterson"),TO); }

  if(arg) return;
set_light(0);

short_desc = "Drygulch Hotel basement";
long_desc =
	"  As you rummage around the basement, you come across some old \n"+
	"wooden kegs left scattered about.  There are footprints in the \n"+
	"dirt floor but they may have been here for ages. \n";

items = ({
	"kegs","These wooden containers are used to ship different items \n"+
		"that the hotel uses from whiskey to flour",
	"footprints","Made from a fairly large boot...hard to tell the age",
});

dest_dir = ({
	"/players/eurale/Hotel/dghb1.c","east",
});

}
