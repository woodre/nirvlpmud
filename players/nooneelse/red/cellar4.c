/*
 cellar4.c
*/

inherit "room/room";

init() {
  ::init();

  add_action("sniff",      "sniff");
}

sniff() {
  write("As you sniff, the dust tickles your nose.\n");
  command("sneeze", this_player());
  return 1;
}

realm() { return "NT"; }

reset(arg) {
  if (arg) return;

  set_light(0);
  short_desc = "west end of cellar hall";
  no_castle_flag=1;
  long_desc =
    "You have reached the west end of this musty hallway.  There is\n"
    + "a large room to the south.  There are some strange scratching tracks\n"
    + "in the dust on the floor.\n";
  items =
    ({
      "tracks", "They seem to be the tracks of something with strong claws.",
      "scratches", "They seem to be the tracks of something with strong claws.",
      "dust", "It's very fine powdery dust.",
    });
  dest_dir =
    ({
      "players/nooneelse/red/cellar5", "south",
      "players/nooneelse/red/cellar3", "east",
    });
}
