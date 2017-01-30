/*
 beach_3.c
*/

inherit "room/room";

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc = "a beach with warm sand";
  no_castle_flag=1;
  long_desc =
    "This clean, trackless warm beach between the sea and a jungle.\n";
  dest_dir =
    ({
      "players/nooneelse/sea/beach_2", "west",
      "players/nooneelse/sea/beach_4", "east",
      "players/nooneelse/sea/jungle_3", "south",
      "players/nooneelse/sea/sea_3", "down",
    });
}
