/*
  m_forest_cave2.c
*/

inherit "room/room";

realm() { return "NT"; }

reset(arg) {
  if (arg) return 0;

  set_light(0);
  short_desc="A dark cave";
  long_desc="You are in the back room of a dark cave.  It looks like a\n"+
            "really large creature sleeps here sometimes.\n";
  dest_dir=({
             "players/nooneelse/mazeforest/m_forest_cave1", "west",
           });
}
