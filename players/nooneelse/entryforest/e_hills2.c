/*
  e_hills2.c
*/

inherit "room/room";

realm() { return "NT"; }

reset(arg) {
  if (arg) return 0;

  set_light(0);
  short_desc="Low hills";
  long_desc="You are in some low hills.\n";
  dest_dir=({
             "players/nooneelse/entryforest/e_hills1", "north",
             "players/nooneelse/entryforest/e_hills4", "west",
          });
}
