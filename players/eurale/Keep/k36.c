#include "/players/eurale/closed/ansi.h"
#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"  The tunnel curves south here and continues to descend.  You\n"+
	"can hear a strange type of 'echo' coming from farther south \n"+
	"like there might be some kind of cavern.  The temperature of\n"+
	"the air has risen slightly and feels more comfortable.\n";

items = ({
});

dest_dir = ({
	"players/eurale/Keep/k22.c","east",
	"players/eurale/Keep/k37.c","south",
});

}
