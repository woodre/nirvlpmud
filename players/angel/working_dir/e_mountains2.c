/*
  e_mountains2.c
*/

inherit "room/room";

realm() { return "NT"; }

reset(arg) {
  if (arg) return 0;

  set_light(0);
  short_desc="Low mountains";
  long_desc=
           "You are in some low mountains above a granite quarry pit.  There\n"+
           "is a path leading north, a small path down into the pit and one\n"+
           "leading up to the higher peaks.\n";
  dest_dir=({
             "players/nooneelse/entryforest/e_hills3", "east",
             "players/nooneelse/entryforest/e_mountains3", "up",
             "players/nooneelse/entryforest/e_granite_quarry", "down",
           });
}
