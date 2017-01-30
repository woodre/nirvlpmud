/*
  e_marble_quarry_pit.c
*/

inherit "room/room";

realm() { return "NT"; }

reset(arg) {
  object golem;
  if (arg) return 0;

  set_light(1);
  short_desc="Bottom of quarry";
  long_desc="You are at the bottom of a marble quarry pit.  There is a path"+
           " leading up.\n";
  dest_dir=({
             "players/nooneelse/entryforest/e_marble_quarry", "up",
          });
  if (!find_living("marble golem")) {
    golem=clone_object("players/nooneelse/mon/marble_golem");
    move_object(golem, this_object());
  }
}
