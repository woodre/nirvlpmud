/*
 romulan_corridor1.c
*/

#include "/players/nooneelse/romulan/romulan_warbird.h"

inherit "room/room";

int door_is_open;

init() {
  ::init();

  add_action("port", "port");
}

port() {
  if (door_is_open) return;
  if (!present("romulan security key", this_player())) {
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
  short_desc=("the Main corridor");
  long_desc="This is the main corridor of this Romulan Warbird.  The\n"+
            "deck, ceiling and walls are constructed of riveted gray steel.\n"+
            "The corridor leads forward toward the bridge and aft toward\n"+
            "engineering.  The Captain's cabin is port and the First\n"+
            "Officer's cabin is starboard.\n";
  door_is_open=0;
  no_castle_flag=1;
  items=
        ({
          "rivet", "A dull gray steel rivet",
          "rivets", "Dull gray steel rivets",
        });
  dest_dir=
    ({
      "players/nooneelse/romulan/romulan_bridge", "fore",
      "players/nooneelse/romulan/romulan_corridor2", "aft",
      "players/nooneelse/romulan/romulan_first_officer", "starboard",
      "players/nooneelse/romulan/romulan_captain", "port",
    });
  return;
}

realm() { return "NT"; }
