#include "/players/eurale/defs.h"
inherit "room/room";

reset(arg) {
if(!present("dragon")) {
move_object(clone_object("players/eurale/Keep/NPC/astral_dragon"),TO); }
  if(arg) return;
set_light(1);

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"You stand in the Astral Dragon's lair.  There are golden\n"+
	"scales covering the floor which reflect enough of the river's\n"+
	"flames to light the area.  The rest of the lair is built \n"+
	"entirely of black crystal supplied by the gods.\n";

items = ({
	"scales","Large, golden-colored scales",
	"crystal","Jet black and perfect, it glitters in the flickering\n"+
		"light of the river's reflection",
});

dest_dir = ({
	"players/eurale/Keep/k17.c","keep",
});

}

realm() { return "NT"; }
