#include "def.h"

inherit ROOM;

object vendor;

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="The Stands";
  long_desc=
"Row upon row of seats overlook the sparring arena below.  From\n"+
"here, you have an excellent view of the drama taking place beneath\n"+
"you in the arena.\n";

  dest_dir=({
    "/players/feldegast/arena/rooms/spar_entry","down"
  });
}
query_no_fight() {
  return 1;
}
    
