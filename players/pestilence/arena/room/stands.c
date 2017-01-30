/* Based on Feld's arena */
#include "/players/pestilence/define.h"

inherit ROOM;

object vendor;

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc=""+HIB+"Bleachers"+NORM+"";
  long_desc=
"A long section of bleachers stretch from one end to the other end.\n"+
"From this location, there is an incredible view of the large open\n"+
"arena, below.\n";

  dest_dir=({
    "/players/pestilence/arena/room/entry","down"
  });
}
query_no_fight() {
  return 1;
}
