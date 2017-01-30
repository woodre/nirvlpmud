/*
 sea_19.c
*/

inherit "room/room";

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc = "in a water filled tunnel";
  no_castle_flag=1;
  long_desc =
    "You are in a tunnel carved out of the stone.  It is filled with water.\n";
  dest_dir =
    ({
      "players/nooneelse/sea/sea_18", "north",
      "players/nooneelse/sea/island_diving_room", "up",
    });
}
