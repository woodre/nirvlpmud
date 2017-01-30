/*
  e_granite_quarry_pit.c
*/

inherit "room/room";

realm() { return "NT"; }

reset(arg) {
  object golem;
  if (arg) return 0;

  set_light(1);
  short_desc="Bottom of quarry";
  long_desc="You are at the bottom of a granite quarry pit.  There is a path"+
           " leading up.\n";
  dest_dir=({
             "players/nooneelse/entryforest/e_granite_quarry", "up",
          });
  if (!find_living("granite golem")) {
    golem=clone_object("players/nooneelse/mon/granite_golem");
    move_object(golem, this_object());
  }
}
