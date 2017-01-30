/*
 jungle_13.c
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
      "players/nooneelse/sea/jungle_9", "north",
      "players/nooneelse/sea/jungle_14", "east",
      "players/nooneelse/sea/jungle_10", "west",
      "players/nooneelse/sea/jungle_17", "south",
    });
}
