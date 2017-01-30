/* Just a room to mess around with. */
#include "/players/feldegast/defines.h"
inherit ROOM;
reset(arg) {
  if (arg) return;
  set_light(1);
  set_pk(1);
  short_desc="A fencing studio";
  long_desc=
"  This is a large vaulted chamber with a great deal of floorspace\n\
for practice fights.  A large stained glass window sheds light into\n\
the room from the east.  The walls are covered with decorative, but\n\
merely aesthetic swords and axes.\n";
  items=({
  });
  dest_dir=({
    "/players/feldegast/closed/tower/tower1","west"
  });
}
query_spar_area() { return 1; }

init() {
  ::init();
  TP->set_pl_k("spar");
}
