#include "DEFS.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
if(!present("dizantar")) {
  move_object(clone_object("players/eurale/Space/NPC/dizantar"),TO); }
set_light(0);

short_desc = "Deep Space";
long_desc =
  "  You find a small hand hold and carefully climb up into this low-\n"+
  "ceilinged niche.  It is very well hidden from view but provides\n"+
  "enough room to crawl around... although the "+RED+"red crystaline rocks"+NORM+"\n"+
  "are sharp and hurt your knees...\n";

items = ({
});

dest_dir = ({
	"players/eurale/Space/ds5.c","out",
});

}
