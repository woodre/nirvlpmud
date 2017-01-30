#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
#include "/players/anshar/closed/mydef.h"
inherit "room/room";

reset(arg) {
  if (arg) return 0;

  set_light(1);
  short_desc="A dusty road";
  long_desc="    Slightly windingly, the path continues south with no end\n"+
            "in sight. There are some scuffs in the dust here. The sun is\n"+
            "relentless in its hatred as it glares above. The brush still\n"+
            "frames the path to either side.\n";
  items=({
    "path", "The dusty path winds far to the north and south",
    "dust", "Marks that may be footprints appear here, though they could be older",
    "scuffs", "Marks that may be footprints appear here, though they could be older",
    "footprints", "Definitely footprints, and heading in a southerly direction",
    "sun",  "Large and angry red, the sun beats down upon you fiercely",
    "brush", "The brush is brown and scrawny, the remains of lush hedge fence",
    "fence",  "A scraggly hedge fence, framing the path",
  });
  dest_dir=({
    FROOM+"path1", "north",
    FROOM+"path3", "south",
  });
}
