/*
 beach_4.c
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
      "players/nooneelse/sea/beach_3", "west",
      "players/nooneelse/sea/beach_2", "east",
      "players/nooneelse/sea/jungle_4", "south",
      "players/nooneelse/sea/sea_4", "down",
    });
}
