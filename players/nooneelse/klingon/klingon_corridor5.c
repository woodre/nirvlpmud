/*
 klingon_corridor5.c
*/

#include "/players/nooneelse/klingon/klingon_ship.h"

inherit "room/room";

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc=("the Main corridor");
  long_desc="This is the main corridor of this Klingon scout ship.  The\n"+
            "deck, ceiling and walls are constructed of riveted gray steel.\n"+
            "There is a doorway aft to engineering, there are doorways\n"+
            "leading to two other rooms, a steel ladder going to a level\n"+
            "above and the corridor continues forward toward the bridge.\n";
  no_castle_flag=1;
  items=
    ({
      "rivet", "A dull gray steel rivet",
      "rivets", "Dull gray steel rivets",
      "doorway", "An opening in the steel plates of the wall",
      "doorways", "Openings in the steel plates of the walls",
      "ladder", "A steel runged ladder leading through the plates "+
                "of the ceiling",
    });
  dest_dir=
    ({
      "players/nooneelse/klingon/klingon_corridor4", "fore",
      "players/nooneelse/klingon/klingon_engineering", "aft",
      "players/nooneelse/klingon/klingon_crew3", "starboard",
      "players/nooneelse/klingon/klingon_crew4", "port",
      "players/nooneelse/klingon/klingon_corridor6", "up",
    });
  return;
}

realm() { return "NT"; }
