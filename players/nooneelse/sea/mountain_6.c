/*
 mountain_6.c
*/

inherit "room/room";

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc = "on a mountain";
  no_castle_flag=1;
  long_desc =
    "You are on the side of a dry rocky mountain.\n";
  dest_dir =
    ({
      "players/nooneelse/sea/mountain_10", "north",
      "players/nooneelse/sea/mountain_7", "east",
      "players/nooneelse/sea/mountain_4", "west",
      "players/nooneelse/sea/mountain_2", "south",
    });
}
