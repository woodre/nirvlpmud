#include "/players/eurale/defs.h"
inherit "room/room";

reset(arg) {
if(!present("disir")) {
move_object(clone_object("players/eurale/Keep/NPC/disir"),TO); }
if(!present("disir 2")) {
move_object(clone_object("players/eurale/Keep/NPC/disir2"),TO); }
  if(arg) return;
set_light(0);

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"  The cave has reached a flat area covered with bones and partial\n"+
	"carcasses.  This appears to be the lair of one of the subter-\n"+
	"ranean creatures known as Disirs.\n";

items = ({
	"bones","They appear to be from both animal and adventurer",
	"carcasses","Partially eaten and decaying remains of some kind\n"+
		"of large animal",
});

dest_dir = ({
	"players/eurale/Keep/k8.c","up",
});

}
