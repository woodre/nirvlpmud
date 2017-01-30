/*
 sea_15.c
*/

inherit "room/room";

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc = "the bottom of the sea";
  no_castle_flag=1;
  long_desc =
    "You are at the bottom of a clear, calm sea.\n"+
    "There seems to be a wrecked ship sitting on the bottom to the east.\n";
  dest_dir =
    ({
      "players/nooneelse/sea/sea_15", "north",
      "players/nooneelse/sea/sea_15", "west",
      "players/nooneelse/sea/wrecked_ship_deck", "east",
      "players/nooneelse/sea/sea_14", "south",
    });
}
