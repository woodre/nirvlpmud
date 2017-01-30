/*
 romulan_corridor1.c
*/

#include "/players/nooneelse/romulan/romulan_warbird.h"

inherit "room/room";

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc=("the Main corridor");
  long_desc="This is the main corridor of this Romulan Warbird.  The\n"+
            "deck, ceiling and walls are constructed of riveted gray steel.\n"+
            "The corridor leads forward toward the bridge and aft toward\n"+
            "engineering.  There are crew's quarters to port and starboard.\n";
  no_castle_flag=1;
  items=
        ({
          "rivet", "A dull gray steel rivet",
          "rivets", "Dull gray steel rivets",
        });
  dest_dir=
    ({
      "players/nooneelse/romulan/romulan_corridor1", "fore",
      "players/nooneelse/romulan/romulan_engineering", "aft",
      "players/nooneelse/romulan/romulan_crew2", "starboard",
      "players/nooneelse/romulan/romulan_crew1", "port",
    });
  return;
}

realm() { return "NT"; }
