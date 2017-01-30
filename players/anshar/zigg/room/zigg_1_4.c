#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
#include "/players/anshar/closed/mydef.h"
inherit "room/room";

reset(arg) {
  if (arg) return 0;

  set_light(0);
  short_desc=(HIR+"The Zodiac Temple"+NORM);
  long_desc="     The entrance to the temple consists of a small, dark room\n"+
            "with the smell of dust strong in the air. All about, the signs\n"+
            "of age, looters, and more recent signs of struggle are in evidence.\n"+
            "The only sign of wealth is a large circle apon the ground which\n"+
            "appears to be made of some glinting metal.\n";
  items=({
    "enterance",  "The enterance is covered by dense plants",
    "dust",  "Dust covers everything with a fine coat",
    "signs",  "There are signs of age, and looters and struggle",
    "age",  "The room screams antiquity",
    "looters",  "It appears the room has been cleaned of all treasure",
    "struggle",  "A struggle has obviously taken place here fairly recently",
    "wealth",  "The only possible wealth here is marked into the floor",
    "floor",  "A circle of glinting metal is inset into the floor",
    "circle",  "A metal circle marked my twelve points is inset in the floor",
    "metal",  "Closer inspection reveals gold, though there is no way to retrieve it",
  });
  dest_dir=({
    ZROOM+"zigg_1_9", "south",
    ZROOM+"zigg_1_3", "west",
    ZROOM+"zigg_1_5", "east",
    ZROOM+"zigg_1_1", "back",
  });

}

realm() {return "NT"; }
