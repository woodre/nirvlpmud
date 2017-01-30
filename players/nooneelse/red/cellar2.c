/*
 cellar2.c
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
  short_desc = "cellar hall";
  no_castle_flag=1;
  long_desc =
    "This hallway continues east and west.  It is so covered with\n"
    + "dust that your every step raises a choking cloud.\n";
  items =
    ({
      "dust", "It's very fine powdery dust.",
    });
  dest_dir =
    ({
      "players/nooneelse/red/cellar3", "west",
      "players/nooneelse/red/cellar1", "east",
    });
}
