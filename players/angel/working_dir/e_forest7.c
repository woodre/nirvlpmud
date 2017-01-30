/*
  e_forest7.c
*/

inherit "room/room";

realm() { return "NT"; }

reset(arg) {
  object rabbit;
  if (arg) return 0;

  set_light(1);
  short_desc="A dimly lit forest";
  long_desc="You are in part of a dimly lit forest.\n";
  items=({
         "forest", "It is full of trees",
         "trees", "They are mostly oak",
         "tree", "This one seems to be a sturdy redwood",
         "trails",
           "They seem to be somewhat clear paths between the trees",
         "trail",
           "It seems to be a somewhat clear path between the trees",
       });
  dest_dir=({
             "players/nooneelse/entryforest/e_forest8", "north",
             "players/nooneelse/entryforest/e_forest3", "east",
             "players/nooneelse/entryforest/e_forest10", "west",
             "players/nooneelse/entryforest/e_forest6", "south",
          });
  if (!find_living("little rabbit")) {
    rabbit=clone_object("players/nooneelse/mon/rabbit");
    move_object(rabbit, this_object());
  }
}
