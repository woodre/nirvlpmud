/*
  m_forest20.c
*/

inherit "room/room";

realm() { return "NT"; }

reset(arg) {
  object druid;
  if (arg) return 0;

  set_light(0);
  short_desc="A clearing in a dark forest";
  long_desc=
    "You are in a clearing in a part of a dark forest.  There is a dark\n"+
    "staircase leading down.\n";
  items=({
          "staircase", "It is carved into solid granite and leads down",
          "stairs", "They are carved into solid granite and lead down",
          "forest", "It is a full of trees",
          "trees", "They are mostly oak",
          "tree", "This one seems to be a sturdy redwood",
          "trails",
            "They seem to be somewhat clear paths between the trees",
        });
  dest_dir=({
             "players/nooneelse/mazeforest/m_forest0", "north",
             "players/nooneelse/mazeforest/m_forest0", "east",
             "players/nooneelse/mazeforest/m_forest0", "south",
             "players/nooneelse/mazeforest/m_forest0", "west",
             "players/nooneelse/mazeforest/m_forest_chamber", "down",
           });
  if (!find_living("sebastion")) {
    druid=clone_object("players/nooneelse/mon/druid");
    move_object(druid, this_object());
  }
}
