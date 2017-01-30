#include "../def.h"
inherit ROOM;
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="Bronze Street";
  long_desc=
"  Bronze street ends here in front of the infamous Coliseum of Haven,\n"+
"an institution that is the stuff of myth and legend.  The coliseum\n"+
"itself is a huge circular building whose high walls dominate the\n"+
"cityscape for miles around.  The coliseum's gates are, as always, open\n"+
"to all who seek to enter.\n";
  items=({
    "coliseum","A huge circular building with high walls",
  });
  dest_dir=({
    "/players/feldegast/arena/rooms/foyer","north",
    PATH+"Haven/bronze1","south"
  });
}   
