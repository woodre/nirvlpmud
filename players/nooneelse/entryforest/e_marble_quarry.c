/*
  e_marble_quarry.c
*/

inherit "room/room";

realm() { return "NT"; }

reset(arg) {
  if (arg) return 0;

  set_light(1);
  short_desc="Marble quarry";
  long_desc="You are in a marble quarry pit.\n"+
           "There is a path leading up and one leading further down into\n"+
           "the pit.\n";
  dest_dir=({
             "players/nooneelse/entryforest/e_mountains1", "up",
             "players/nooneelse/entryforest/e_marble_quarry_pit", "down",
          });
}
