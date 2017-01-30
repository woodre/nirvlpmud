#include "/players/eurale/closed/ansi.h"
#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"  This tunnel through the solid rock has seen much use.  The floor\n"+
	"is worn smooth and the torches flicker casting eerie shadows\n"+
	"up and down the walls.  The dank air has a musty odor.\n";

items = ({
	"floor","Solid rock and smooth",
	"torches","Wooden handles with lighted, burning ends",
});

dest_dir = ({
	"players/eurale/Keep/k2.c","north",
	"players/eurale/Keep/k20.c","south",
});

}

init() {
  ::init();
  add_action("smell","smell");
}

smell(str) {
if(!str) { write("What are you trying to smell?\n"); return 1; }
if(str == "odor" || str == "air" || str == "musty odor") {
  write("The air smells old with a strangeness to it..\n");
  return 1; }
}
