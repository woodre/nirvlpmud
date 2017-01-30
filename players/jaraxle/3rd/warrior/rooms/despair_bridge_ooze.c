#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Third Earth Bridge";
long_desc =
  "  A very short wooden bridge crossing over the River of Despair.\n"+
  "A grotesque ooze can be seen at the edge of the bridge to the\n"+
  "west.  To the east a forest flourishes wonderously.\n";
items = ({
  "bridge","A short bridge made of wood logs, tied with rope",
  "river","A wonderously clean looking river",
  "river of despair","A wonderously clean looking river",
  "ooze","You really can't make out what it is... it looks strange",
  "forest","A dense thicket of trees, thick with massive amounts of foliage",
});

dest_dir = ({
  "/players/jaraxle/3rd/warrior/rooms/roomw_bridge.c","cross_east",
  "/players/jaraxle/3rd/ooze/rooms/room.c","cross_west",
});

}

