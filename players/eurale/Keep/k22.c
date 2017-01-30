#include "/players/eurale/closed/ansi.h"
#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"  The tunnel is descending rapidly and the air has taken on a\n"+
	"different quality.... like a change in humidity.  The walls\n"+
	"and floor of the tunnel also seem to have more moss growing\n"+
	"on them.\n";

items = ({
	"moss","Green and moist",
});

dest_dir = ({
	"players/eurale/Keep/k20.c","east",
	"players/eurale/Keep/k36.c","west",
});

}
