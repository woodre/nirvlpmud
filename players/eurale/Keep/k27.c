#include "/players/eurale/closed/ansi.h"
#define tpn this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"  This is a fairly wide stairway leading up and back down to\n"+
	"the tunnel.  It seems to go nearly straight up.  The walls of\n"+
	"stone have developed some fairly large cracks from the immense\n"+
	"weight and the shifting of the stone over time.  It appears to\n"+
	"to be somewhat lighter farther up.\n";

items = ({
	"stairway","Large, wide stone steps",
	"cracks","Dark, wide gashes in the stone that a small person\n"+
		"might be able to squeeze into",
	"walls","Solid gray stone",
});

dest_dir = ({
	"players/eurale/Keep/k21.c","down",
	"players/eurale/Keep/k30.c","up",
});

}

init() {
  ::init();
  add_action("squeeze","squeeze");
}

squeeze(str) {
if(!str) { write("What are you trying to squeeze into?\n"); return 1; }
if(str == "crack" || str == "gash") {
  write("You squeeze yourself into this very narrow crack...\n");
  this_player()->move_player("crack#players/eurale/Keep/k28.c");
  return 1; }
}
