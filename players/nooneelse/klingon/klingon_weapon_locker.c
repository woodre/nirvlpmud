/*
 klingon_weapon_locker.c
*/

#include "/players/nooneelse/klingon/klingon_ship.h"

inherit "room/room";

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc=("Weapon Locker");
  long_desc=
    "This is the weapon locker of this Klingon scout ship.  The\n"+
    "deck, ceiling and walls are constructed of riveted gray steel.\n"+
    "There is one doorway leading forward to the Security Section.\n";
  no_castle_flag=1;
  items=
    ({
      "rivet", "A dull gray steel rivet",
      "rivets", "Dull gray steel rivets",
      "doorway", "An opening in the steel plates of the wall",
    });
  dest_dir=
    ({
      "players/nooneelse/klingon/klingon_security", "fore",
    });
  move_object(clone_object("/players/nooneelse/klingon/klingon_armor"),
              this_object());
  move_object(clone_object("/players/nooneelse/klingon/klingon_boots"),
              this_object());
  move_object(clone_object("/players/nooneelse/klingon/klingon_gloves"),
              this_object());
  move_object(clone_object("/players/nooneelse/klingon/klingon_disrupter"),
              this_object());
  return;
}

realm() { return "NT"; }
