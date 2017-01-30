#include "/players/eurale/closed/ansi.h"
#define TPN this_player()->query_name()
#define TP this_player()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "S";
long_desc =
  "Long description.\n";

items = ({
  "item","Item description",
});

dest_dir = ({
	"players/wizard/area/rm.c","north",
});

}
