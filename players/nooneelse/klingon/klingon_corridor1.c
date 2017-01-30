/*
 klingon_corridor1.c
*/

#include "/players/nooneelse/klingon/klingon_ship.h"

inherit "room/room";

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc=("the Main corridor");
  long_desc="This is the main corridor of this Klingon scout ship.  The\n"+
            "deck, ceiling and walls are constructed of riveted gray steel.\n"+
            "A doorway leads forward to the bridge, two doorways lead to\n"+
            "other rooms and the corridor continues aft toward engineering.\n";
  no_castle_flag=1;
  items=
      ({
        "rivet", "A dull gray steel rivet",
        "rivets", "Dull gray steel rivets",
        "doorway", "An opening in the steel plates of the wall",
        "doorways", "Openings in the steel plates of the walls",
      });
  dest_dir=
    ({
      "players/nooneelse/klingon/klingon_bridge", "fore",
      "players/nooneelse/klingon/klingon_corridor2", "aft",
      "players/nooneelse/klingon/klingon_security", "starboard",
      "players/nooneelse/klingon/klingon_science", "port",
    });
  return;
}

realm() { return "NT"; }
