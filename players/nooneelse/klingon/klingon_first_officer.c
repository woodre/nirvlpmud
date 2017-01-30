/*
 klingon_first_officer.c
*/

#include "/players/nooneelse/klingon/klingon_ship.h"

inherit "room/room";

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc=("First Officer's Quarters");
  long_desc=
    "This is the first officer's quarters of this Klingon scout ship.\n"+
    "The deck, ceiling and walls are constructed of riveted gray steel.\n"+
    "Other than the sleeping platform riveted to the wall, the room is\n"+
    "bare.  There is one doorway leading out into the corridor.\n";
  no_castle_flag=1;
  items=
    ({
      "rivet", "A dull gray steel rivet",
      "rivets", "Dull gray steel rivets",
      "doorway", "An opening in the steel plates of the wall",
      "platform", "A platform made of smooth steel, riveted to the wall",
    });
  dest_dir=
    ({
      "players/nooneelse/klingon/klingon_corridor6", "port",
    });
  return;
}

realm() { return "NT"; }
