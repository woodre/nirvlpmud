#define tpn this_player()->query_name()
#include "/players/eurale/closed/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Deep Space";
long_desc =
	"long";

items = ({
});

dest_dir = ({
	"players/eurale/Space/N.c","north",
	"players/eurale/Space/DS.c","south",
	"players/eurale/Space/E.c","east",
	"players/eurale/Space/W.c","west",
});

}
