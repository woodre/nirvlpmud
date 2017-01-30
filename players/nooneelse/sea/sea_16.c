/*
 sea_16.c
*/

inherit "room/room";

object suit;

init() {
  ::init();

  add_action("north", "north");
}

north() {
  suit=present("diving suit", this_player());
  if (suit) suit->set_suit_is_torn(1);
  write("Oh no!  As you were plodding along, you tore your diving suit on\n"+
        "a sharp piece of coral!\n");
}

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc = "the bottom of the sea";
  no_castle_flag=1;
  long_desc =
    "You are at the bottom of a clear, calm sea.  There is some\n"+
    "really pretty coral here in the sand.\n";
  items =
    ({
      "coral", "It is a beautiful chunk of red coral sticking up out of "+
               "the sand.",
    });
  dest_dir =
    ({
      "/room/sea_bottom", "north",
      "players/nooneelse/sea/sea_17", "west",
      "players/nooneelse/sea/sea_17", "east",
      "players/nooneelse/sea/sea_16", "south",
    });
}
