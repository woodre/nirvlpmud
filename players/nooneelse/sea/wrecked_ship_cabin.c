/*
 wrecked_ship_cabin.c
*/

inherit "room/room";

init() {
  ::init();

  add_action("aft", "aft");
}

aft() {
  if (present("skeleton")) {
    write("The skeleton blocks your way.\n");
    return 1;
  }
}

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc = "the cabin of a sunken ship";
  no_castle_flag=1;
  long_desc =
    "You are in the cabin of a sunken ship\n";
  dest_dir =
    ({
      "players/nooneelse/sea/wrecked_ship_deck", "fore",
      "players/nooneelse/sea/wrecked_ship_stateroom", "aft",
    });
}
