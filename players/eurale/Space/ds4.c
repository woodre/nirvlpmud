#define tpn this_player()->query_name()
#include "/players/eurale/closed/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Deep Space";
long_desc =
  "  You climb down below the rim of this crater.  Everything has an\n"+
  "eerie "+RED+"red glow"+NORM+" to it.  There seems to be a narrow path continuing\n"+
  "deeper into the crater.  It is getting darker as you descend but\n"+
  "the beauty of this glossy red stone beckons you to continue.\n";

items = ({
	"path","Barely visible but there none-the-less",
	"stone","Red, ice-like stone",
});

dest_dir = ({
	"players/eurale/Space/ds3.c","out",
	"players/eurale/Space/ds5.c","down",
});

}
