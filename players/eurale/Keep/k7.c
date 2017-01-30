#include "/players/eurale/defs.h"
inherit "room/room";

reset(arg) {
if(!present("disir 3")) {
move_object(clone_object("players/eurale/Keep/NPC/disir3"),TO); }
if(!present("disir 2")) {
move_object(clone_object("players/eurale/Keep/NPC/disir2"),TO); }
  if(arg) return;
set_light(0);

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"  This part of the tunnel system seems to be fairly new.  There\n"+
	"are no torches here yet and the floor of the tunnel seems to be\n"+
	"much rougher indicating much less traffic has used it.  The air\n"+
	"has a pungent odor.  Large, rotting pieces of meat litter the\n"+
	"tunnel.\n";

items = ({
	"meat","Green and decaying pieces of meat, unrecognizable",
});

dest_dir = ({
	"players/eurale/Keep/k6.c","north",
});

}

init() {
  ::init();
  add_action("smell","smell");
}

smell(str) {
if(!str) { write("What are you trying to smell?\n"); return 1; }
if(str == "odor" || str == "air" || str == "pungent odor") {
  write("You inhale... and the sting of this putrid air burns your\n"+
	"nose and makes your eyes water.  It is the smell of rotting\n"+
	"and decaying flesh.\n");
  TP->add_hit_point(-(15 + random(20)));
  return 1; }
}
