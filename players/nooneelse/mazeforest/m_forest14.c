/*
  m_forest14.c
*/

inherit "room/room";

realm() { return "NT"; }

reset(arg) {
  if (arg) return 0;

  set_light(0);
  short_desc="A dark forest";
  long_desc="You are in part of a dark forest.\n";
  items=({
          "forest", "It is a full of trees",
          "trees", "They are mostly oak",
          "tree", "This one seems to be a sturdy redwood",
          "trails",
            "They seem to be somewhat clear paths between the trees",
          "trail",
            "It seems to be a somewhat clear path between the trees",
        });
  dest_dir=({
             "players/nooneelse/mazeforest/m_forest1", "north",
             "players/nooneelse/mazeforest/m_forest0", "east",
             "players/nooneelse/mazeforest/m_forest15", "south",
             "players/nooneelse/mazeforest/m_forest0", "west",
           });
}
