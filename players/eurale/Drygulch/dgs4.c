#include "/players/eurale/closed/ansi.h"
#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Drygulch";
long_desc =
	"  You stand at the beginning of what looks like a never-ending \n"+
	"road leading off to the east.  The greenness around you gives \n"+
	"way to desert as you gaze east.  Travelers heading off seem to \n"+
	"be well-stocked and prepared for the hardships they face.\n";

items = ({
	"road","A well-traveled roadway",
	"travelers","These folks are in search of something better.  Some \n"+
		"have all thier belongings while other have mining and \n"+
		"prospecting gear.  Each has hope in their eyes",
});

dest_dir = ({
	"/players/eurale/Drygulch/dgs3.c","east",
	"/players/eurale/RMS/warp.c","warp",
});

}
