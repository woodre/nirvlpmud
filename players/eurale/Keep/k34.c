#include "/players/eurale/defs.h"
inherit "room/room";

reset(arg) {
if(!present("warrior")) {
move_object(clone_object("players/eurale/Keep/NPC/shadow_warrior"),TO); }
  if(arg) return;
set_light(0);

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"  The tunnel works it's way around a particularly large boulder\n"+
	"and then comes to an abrupt dead end.\n";

items = ({
	"boulder","A huge rock, trapped when the stone was formed",
});

dest_dir = ({
	"players/eurale/Keep/k30.c","north",
});

}
