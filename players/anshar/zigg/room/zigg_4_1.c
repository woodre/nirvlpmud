
#include "/players/anshar/closed/ansi.h"
#include "/players/anshar/closed/mydef.h"
inherit "room/room";

reset(arg) {
  if (arg) return 0;

  set_light(0);
  short_desc=(HIR+"The Zodiac Temple"+NORM);
  long_desc="stuff\n"+
            "stuff\n"+
            "stuff\n"+
            "stuff\n"+
            "There is a staircase up to the southeast.\n";
  items=({
    "stuff",  "stuff",
  });
  dest_dir=({
    ZROOM+"zigg_4_3", "south",
    ZROOM+"zigg_4_2", "east",
    ZROOM+"zigg_5_1", "up",
  });

}

realm() {return "NT"; }
