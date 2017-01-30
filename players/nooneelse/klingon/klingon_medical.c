/*
 klingon_medical.c
*/

#include "/players/nooneelse/klingon/klingon_ship.h"

inherit "room/room";

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc=("the Medical Section");
  long_desc=
    "This is the medical section of this Klingon scout ship.  The\n"+
    "deck, ceiling and walls are constructed of riveted gray steel.\n"+
    "You see one metal platform here where injured Klingons's sit\n"+
    "while waiting for the Science Officer to get around to patching\n"+
    "them up.  There is one doorway leading forward to the Science Section.\n";
  no_castle_flag=1;
  items=
    ({
      "rivet", "A dull gray steel rivet",
      "rivets", "Dull gray steel rivets",
      "doorway", "An opening in the steel plates of the wall",
      "platform", "A flat steel plate set in the wall a couple of feet\n"+
                  "off the floor, with small holes to drain off the blood",
    });
  dest_dir=
    ({
      "players/nooneelse/klingon/klingon_science", "fore",
    });
  return;
}

realm() { return "NT"; }
