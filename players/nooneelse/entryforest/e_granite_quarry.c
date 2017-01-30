/*
  e_granite_quarry.c
*/

inherit "room/room";

realm() { return "NT"; }

reset(arg) {
  if (arg) return 0;

  set_light(1);
  short_desc="Granite quarry";
  long_desc="You are in a granite quarry pit.\n"+
           "There is a path leading up and one leading further down into\n"+
           "the pit.\n";
  dest_dir=({
             "players/nooneelse/entryforest/e_mountains2", "up",
             "players/nooneelse/entryforest/e_granite_quarry_pit", "down",
          });
}
