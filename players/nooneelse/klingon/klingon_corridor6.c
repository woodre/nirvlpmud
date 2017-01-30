/*
 klingon_corridor6.c
*/

#include "/players/nooneelse/klingon/klingon_ship.h"

inherit "room/room";

int door_is_open;

init() {
  ::init();

  add_action("aft", "aft");
}

aft() {
  if (door_is_open) return;
  if (!present("klingon captain key", this_player())) {
    tell_room(this_object(),
        "A brilliant black spark flashes in the doorway, preventing "+
        this_player()->query_name()+"'s entry.\n");
    return 1;
  }
  door_is_open=1;
}

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc=("the Upper corridor");
  long_desc="This is the upper corridor of this Klingon scout ship.  The\n"+
            "deck, ceiling and walls are constructed of riveted gray steel.\n"+
            "There is a doorway forward to auxilliary control, there are\n"+
            "doorways leading to three other rooms, a steel ladder going\n"+
            "to a level below.\n";
  door_is_open=0;
  no_castle_flag=1;
  items=
    ({
      "rivet", "A dull gray steel rivet",
      "rivets", "Dull gray steel rivets",
      "doorway", "An opening in the steel plates of the wall",
      "doorways", "Openings in the steel plates of the walls",
      "ladder", "A steel runged ladder leading through the plates of the floor",
    });
  dest_dir=
    ({
      "players/nooneelse/klingon/klingon_aux_bridge", "fore",
      "players/nooneelse/klingon/klingon_captain", "aft",
      "players/nooneelse/klingon/klingon_first_officer", "starboard",
      "players/nooneelse/klingon/klingon_officers", "port",
      "players/nooneelse/klingon/klingon_corridor5", "down",
    });
  return;
}

realm() { return "NT"; }
