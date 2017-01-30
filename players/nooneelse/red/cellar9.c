/*
 cellar9.c
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
  short_desc = "small wine room";
  no_castle_flag=1;
  long_desc =
    "This room contains several large wooden barrels of the type used\n"
    + "to age wine.  They all have been cracked open and are laying in\n"
    + "ruins.  There are some strange scratching tracks in the dust on\n"
    + "the floor.\n";
  items =
    ({
      "barrels", "They are large wooden wine casks.",
      "barrel", "They are large wooden wine casks.",
      "casks", "They are large wooden wine barrels.",
      "cask", "They are large wooden wine barrels.",
      "tracks", "They seem to be the tracks of something with strong claws.",
      "scratches", "They seem to be the tracks of something with strong claws.",
      "dust", "It's very fine powdery dust.",
    });
  dest_dir =
    ({
      "players/nooneelse/red/cellar3", "north",
      "players/nooneelse/red/cellar5", "west",
    });
}
