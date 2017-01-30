/*
  e_forest1.c
*/

inherit "room/room";

realm() { return "NT"; }

reset(arg) {
  if (arg) return 0;

  set_light(1);
  short_desc="A dimly lit forest";
  long_desc="You are in part of a dimly lit forest.\n";
  items=({
    "forest", "It is full of trees",
    "trees", "They are mostly oak",
    "tree", "This one seems to be a sturdy redwood",
    "trails", "They seem to be somewhat clear paths between the trees",
    "trail", "It seems to be a somewhat clear path between the trees",
  });
  dest_dir=({
    "players/nooneelse/entryforest/e_forest2", "north",
    "players/nooneelse/entryforest/e_forest5", "west",
    "players/nooneelse/entryforest/e_forest0", "south",
  });
}
