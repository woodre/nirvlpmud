/*
 mountain_4.c
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
      "players/nooneelse/sea/mountain_8", "north",
      "players/nooneelse/sea/mountain_5", "east",
      "players/nooneelse/sea/mountain_3", "west",
      "players/nooneelse/sea/mountain_12", "south",
    });
}
