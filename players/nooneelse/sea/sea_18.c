/*
 sea_18.c
*/

inherit "room/room";

init() {
  ::init();

  add_action("north", "north");

  lungs_hurt();
}

north() {
  if (!present("diving suit", this_player())) {
    write("Your lungs hurt too much to continue!  Surface NOW!\n");
    return 1;
  }
}

lungs_hurt() {
  if (!present("diving suit", this_player()))
    write("Your bag has run out of air!  Your lungs are starting to "+
          "hurt a lot!\n"+
          "You better surface NOW!  If you don't, you WILL die!\n");
  return 1;
}

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc = "in a water filled tunnel";
  no_castle_flag=1;
  long_desc =
    "You are in a tunnel carved out of the stone.  It is filled with water.\n";
  dest_dir =
    ({
      "players/nooneelse/sea/sea_19", "south",
      "players/nooneelse/sea/sea_5", "north",
    });
}
