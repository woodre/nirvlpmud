
#include "/players/anshar/closed/ansi.h"
#include "/players/anshar/closed/mydef.h"
inherit "room/room";

reset(arg) {
  if (arg) return 0;

  set_light(0);
  short_desc=(HIR+"The Zodiac Temple"+NORM);
  long_desc="     This is the shrine of Capricorn\n"+
            "stuff\n"+
            "stuff\n"+
            "stuff\n"+
            "stuff\n";
  items=({
    "stuff",  "stuff",
  });
  dest_dir=({
    ZROOM+"zigg_3_2", "north",
    ZROOM+"zigg_3_8", "south",
    ZROOM+"zigg_3_4", "west",
    ZROOM+"zigg_3_6", "east",
  });

}

realm() {return "NT"; }
