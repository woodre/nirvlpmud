#include "/players/eurale/defs.h"
inherit "room/room";

reset(arg) {
if(!present("elder")) {
move_object(clone_object("players/eurale/Keep/NPC/shadow_elder"),TO); }
  if(arg) return;
set_light(1);

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"  You have reached a dead end.  There are fallen rocks on the\n"+
	"floor and a decent size hole in the ceiling through which light\n"+
	"shines.  There is a ring of stones and a pile of pine branches\n"+
	"on the floor.\n";

items = ({
	"rocks","Pieces of the stone through which this tunnel was cut\n"+
		"that have fallen from the ceiling",
	"hole","A hole in the ceiling, left there by the falling rock\n"+
		"that is providing both light and fresh air to the maze\n"+
		"of tunnels in the Keep",
	"stones","A neatly placed ring of stones with ashes inside them,\n"+
		"probably a place where a fire was kept",
	"branches","Neatly piled... looks like a makeshift bed of sorts",
});

dest_dir = ({
	"players/eurale/Keep/k31.c","north",
});

}
