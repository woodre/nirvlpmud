#include "/players/eurale/closed/ansi.h"
#define tpn this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(-1);

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"  You stand at the foot of a long stairway.  The room around\n"+
	"is much like a fortress with it's solid stone walls and floor.\n"+
	"There is an eerie stillness here and the darkness seems to\n"+
	"to be much closer.....\n";

items = ({
});

dest_dir = ({
	"players/eurale/Keep/k24.c","up",
});

}
