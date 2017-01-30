
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
            "stuff\n";
  items=({
    "stuff",  "stuff",
  });
  dest_dir=({
    ZROOM+"zigg_3_3", "north",
    ZROOM+"zigg_3_9", "south",
    ZROOM+"zigg_3_5", "west",
  });

}

realm() {return "NT"; }
