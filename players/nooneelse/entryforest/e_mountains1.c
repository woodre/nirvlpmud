/*
  e_mountains1.c
*/

inherit "room/room";

realm() { return "NT"; }

reset(arg) {
  if (arg) return 0;

  set_light(0);
  short_desc="Low mountains";
  long_desc="You are in some low mountains above a marble quarry pit.\n"+
           "There is a path leading north and a small path down into "+
           "the pit.\n";
  dest_dir=({
             "players/nooneelse/entryforest/e_hills4", "north",
             "players/nooneelse/entryforest/e_marble_quarry", "down",
           });
}
