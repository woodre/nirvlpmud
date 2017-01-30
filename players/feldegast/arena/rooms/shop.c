#include "def.h"

inherit ROOM;

object vendor;

reset(arg) {
  if (arg) return;
  if (!present("vendor")) {
    vendor=clone_object("/players/feldegast/arena/npc/shpkpr");
    move_object(vendor,this_object());
  }
  set_light(1);
  short_desc="The Coliseum's Supply Shop";
  long_desc=
"     This is a small supply shop inside the coliseum.  The room is\n"+
"around ten meters square and filled with racks of armor and equipment.\n"+
"A low counter runs along the side of the shop, behind which is a large\n"+
"sign listing prices.\n";
  dest_dir=({
    "/players/feldegast/arena/rooms/crtyard","north"
  });
  items=({
    "sign","A carved wooden sign sits on the counter",
    "counter","A low wooden counter",
    "racks","Look, but don't touch"
  });
}
query_no_fight() {
  return 1;
}
    
