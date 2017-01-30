/*
 sea_1.c
*/

inherit "room/room";

init() {
  ::init();

  add_action("no_go", "north");
  add_action("no_go", "west");
  add_action("no_go", "east");
}

no_go() {
  if (!present("diving suit", this_player())) {
    if (present("bag", this_player()))
      write("It seems that your bag can't hold enough air.\n");
    write("Your lungs hurt too much to continue!  Surface NOW!\n");
    return 1;
  }
}

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc = "the bottom of the sea";
  no_castle_flag=1;
  long_desc =
    "You are at the bottom of a clear, calm sea.\n";
  dest_dir =
    ({
      "players/nooneelse/sea/beach_1", "up",
      "players/nooneelse/sea/sea_6", "north",
      "players/nooneelse/sea/sea_4", "west",
      "players/nooneelse/sea/sea_2", "east",
    });
}
