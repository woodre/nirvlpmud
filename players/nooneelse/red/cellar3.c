/*
 cellar3.c
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
  short_desc = "cellar hall intersection";
  no_castle_flag=1;
  long_desc =
    "This dark musty hall is difficult to breathe in.  There is a dark\n"
    + "mold growing on the walls and ceiling, and dust covers the floor.\n";
  items =
    ({
      "mold", "It is a dark rusty brown.",
      "dust", "It's very fine powdery dust.",
    });
dest_dir =
  ({
    "players/nooneelse/red/cellar4", "west",
    "players/nooneelse/red/cellar9", "south",
    "players/nooneelse/red/cellar2", "east",
  });
}
