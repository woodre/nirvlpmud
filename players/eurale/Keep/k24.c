#include "/players/eurale/closed/ansi.h"
#define tpn this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"You are on a curved stone stairway.  It is narrow and fairly\n"+
	"steep.  It disappears both up and down.  As you stand here\n"+
	"deep beneath the earth's surface, the sound of silence echoes\n"+
	"from further down below.\n";

items = ({
	"stairway","A narrow, dark, steep curved stairway cut into the\n"+
		"stone.  The slime from the dripping water makes the\n"+
		"steps slippery and the footing treacherous",
});

dest_dir = ({
	"players/eurale/Keep/k25.c","down",
	"players/eurale/Keep/k23.c","up",
});

}
