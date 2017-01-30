/*
 sea_6.c
*/

inherit "room/room";

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc = "the bottom of the sea";
  no_castle_flag=1;
  long_desc =
    "You are at the bottom of a clear, calm sea.\n";
  dest_dir =
    ({
      "players/nooneelse/sea/sea_11", "north",
      "players/nooneelse/sea/sea_5", "west",
      "players/nooneelse/sea/sea_7", "east",
      "players/nooneelse/sea/sea_1", "south",
    });
}
