/*
 jungle_7.c
*/

inherit "room/room";

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc = "a damp warm jungle";
  no_castle_flag=1;
  long_desc =
    "You are in a jungle of dark green, leafy plants.\n";
  dest_dir =
    ({
      "players/nooneelse/sea/jungle_3", "north",
      "players/nooneelse/sea/jungle_5", "east",
      "players/nooneelse/sea/jungle_6", "west",
      "players/nooneelse/sea/jungle_11", "south",
    });
}
