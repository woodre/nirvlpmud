/*
 klingon_corridor3.c
*/

#include "/players/nooneelse/klingon/klingon_ship.h"

inherit "room/room";

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc=("the Main corridor");
  long_desc="This is the main corridor of this Klingon scout ship.  The\n"+
            "deck, ceiling and walls are constructed of riveted gray steel.\n"+
            "The corridor leads forward toward the bridge and aft toward\n"+
            "engineering.\n";
  no_castle_flag=1;
  items=
        ({
          "rivet", "A dull gray steel rivet",
          "rivets", "Dull gray steel rivets",
        });
  dest_dir=
    ({
      "players/nooneelse/klingon/klingon_corridor2", "fore",
      "players/nooneelse/klingon/klingon_corridor4", "aft",
    });
  return;
}

realm() { return "NT"; }
