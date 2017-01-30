/*
 klingon_corridor4.c
*/

#include "/players/nooneelse/klingon/klingon_ship.h"

inherit "room/room";

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc=("the Main corridor");
  long_desc="This is the main corridor of this Klingon scout ship.  The\n"+
            "deck, ceiling and walls are constructed of riveted gray steel.\n"+
            "There are two doorways leading to rooms and the corridor\n"+
            "continues forward toward the bridge and aft toward\n"+
            "engineering.\n";
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
      "players/nooneelse/klingon/klingon_corridor3", "fore",
      "players/nooneelse/klingon/klingon_corridor5", "aft",
      "players/nooneelse/klingon/klingon_crew1", "starboard",
      "players/nooneelse/klingon/klingon_crew2", "port",
    });
  return;
}

realm() { return "NT"; }
