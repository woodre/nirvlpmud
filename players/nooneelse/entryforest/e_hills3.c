/*
  e_hills3.c
*/

inherit "room/room";

realm() { return "NT"; }

reset(arg) {
  if (arg) return 0;

  set_light(0);
  short_desc="Low hills";
  long_desc="You are in some low hills.  They seem to be getting higher to "+
           "the west.\n";
  dest_dir=({
             "players/nooneelse/entryforest/e_hills1", "east",
             "players/nooneelse/entryforest/e_hills4", "south",
             "players/nooneelse/entryforest/e_mountains2", "west",
          });
}
