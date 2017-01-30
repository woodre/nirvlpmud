/*
 sea_5.c
*/

inherit "room/room";

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc = "the bottom of the sea";
  no_castle_flag=1;
  long_desc =
    "You are at the bottom of a clear, calm sea.\n"+
    "To the south there is a tunnel carved into the stone.\n";
  dest_dir =
    ({
      "players/nooneelse/sea/sea_10", "north",
      "players/nooneelse/sea/sea_5", "west",
      "players/nooneelse/sea/sea_6", "east",
      "players/nooneelse/sea/sea_18", "south",
    });
}