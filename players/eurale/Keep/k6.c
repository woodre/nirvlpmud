#include "/players/eurale/closed/ansi.h"
#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"  This part of the tunnel system seems to be fairly new.  There\n"+
	"are no torches here yet and the floor of the tunnel seems to be\n"+
	"much rougher indicating much less traffic has used it.  The air\n"+
	"has a nasty odor.  Large, rotting pieces of meat litter the\n"+
	"tunnel.\n";

items = ({
	"meat","Green and decaying pieces of meat, unrecognizable",
});

dest_dir = ({
	"players/eurale/Keep/k5.c","north",
	"players/eurale/Keep/k7.c","south",
});

}

init() {
  ::init();
  add_action("smell","smell");
}

smell(str) {
int amt;
  if(!str) { write("What are you trying to smell?\n"); return 1; }
  if(str == "odor" || str == "air" || str == "nasty odor") {
  amt = 15 + random(20);
    write("You inhale... and the sting of this putrid air burns your\n"+
	  "nose and makes your eyes water.  It is the smell of rotting\n"+
	  "and decaying flesh.\n");
    this_player()->add_hit_point(-amt);
    return 1; }
}
