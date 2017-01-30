#include "def.h"

inherit ROOM;

object vendor;

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="The Stands";
  long_desc=
"Rows and rows of seats overlook the huge arena below.  From\n"+
"here, you have an excellent view of the events going on below\n"+
"in the arena.\n";

  dest_dir=({
    "/players/feldegast/arena/rooms/foyer","down"
  });
}
query_no_fight() {
  return 1;
}
    
