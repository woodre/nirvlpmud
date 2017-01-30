/*
  e_hills4.c
*/

inherit "room/room";

realm() { return "NT"; }

reset(arg) {
  if (arg) return 0;

  set_light(0);
  short_desc="Low hills";
  long_desc="You are in some low hills.  They seem to be getting higher to\n"+
           "the south.\n";
  dest_dir=({
            "players/nooneelse/entryforest/e_hills3", "north",
            "players/nooneelse/entryforest/e_hills2", "east",
            "players/nooneelse/entryforest/e_mountains1", "south",
          });
}
