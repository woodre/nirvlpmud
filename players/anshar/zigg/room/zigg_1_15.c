#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
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
    ZROOM+"zigg_1_10", "north",
    ZROOM+"zigg_1_20", "south",
    ZROOM+"zigg_1_14", "west",
    ZROOM+"zigg_1_16", "east",
  });

}

realm() {return "NT"; }
