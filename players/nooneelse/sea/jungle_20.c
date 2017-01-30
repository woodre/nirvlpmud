/*
 jungle_20.c
*/

inherit "room/room";

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc = "a damp warm jungle";
  no_castle_flag=1;
  long_desc =
    "You are in a jungle of dark green, leafy plants.  The ground\n"+
    "looks soft here.\n";
  dest_dir =
    ({
      "players/nooneelse/sea/jungle_18", "north",
      "players/nooneelse/sea/jungle_11", "east",
      "players/nooneelse/sea/jungle_19", "west",
      "players/nooneelse/sea/jungle_2", "south",
    });
}
