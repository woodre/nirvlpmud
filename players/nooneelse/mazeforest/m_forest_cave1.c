/*
  m_forest_cave1.c
*/

inherit "room/room";

int mom_called;

realm() { return "NT"; }

reset(arg) {
  object cub_obj;
  if (arg) return 0;

  set_light(0);
  short_desc="A dark cave";
  long_desc="You are in a dark cave.\n";
  dest_dir=({
             "players/nooneelse/mazeforest/m_forest9", "west",
             "players/nooneelse/mazeforest/m_forest_cave2", "east",
           });
  if (!find_living("bear cub")) {
    cub_obj=clone_object("/players/nooneelse/mon/bear_cub");
    move_object(cub_obj, this_object());
    cub_obj=clone_object("/players/nooneelse/mon/bear_cub");
    move_object(cub_obj, this_object());
    cub_obj=clone_object("/players/nooneelse/mon/bear_cub");
    move_object(cub_obj, this_object());
  }
}

mom_called() { mom_called=1; }
query_mom_called() { return mom_called; }
