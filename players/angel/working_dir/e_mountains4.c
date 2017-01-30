/*
  e_mountains4.c
*/

inherit "room/room";

realm() { return "NT"; }

reset(arg) {
  if (arg) return 0;

  set_light(1);
  short_desc="Sphinx holding room";
  long_desc=short()+".\nPlayers should never be able to get here.\n";
  dest_dir=({
             "players/nooneelse/entryforest/e_mountains3", "down",
           });
}
