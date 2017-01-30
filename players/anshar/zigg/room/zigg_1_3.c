#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
#include "/players/anshar/closed/mydef.h"
inherit "room/room";

reset(arg) {
  if (arg) return 0;

  set_light(0);
  short_desc=(HIR+"The Zodiac Temple"+NORM);
  long_desc="     A dusty room filled with rubbish, there is no telling\n"+
            "what purpose this place originally served. There is a skeleton\n"+
            "of some sort lying here like so much garbage.\n";
  items=({
    "rubbish",  "Rubbish clutters the room, nothing of value",
    "garbage",  "Rubbish clutters the room, nothing of value",
    "skeleton",  "Some wayward adventurer whose corpse was looted",
  });
    dest_dir=({
    ZROOM+"zigg_1_8", "south",
    ZROOM+"zigg_1_2", "west",
    ZROOM+"zigg_1_4", "east",
  });

}

realm() {return "NT"; }
