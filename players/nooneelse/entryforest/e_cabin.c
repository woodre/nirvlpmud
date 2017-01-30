/*
  e_cabin.c
*/

inherit "room/room";

realm() { return "NT"; }

clean_up() { return 0; }

reset(arg) {
  object woodsmith_obj;
  if (arg) return 0;

  set_light(1);
  short_desc="A small cabin";
  long_desc="You are in a small log cabin.\n"+
           "You can see the door you entered, one cracked window, a bed,\n"+
           "one chair and an empty table.\n";
  items=({
    "bed", "A clean, sturdy bed made of oak",
    "chair", "A rugged highbacked chair made of green oak",
    "table", "A sturdy table made of green oak",
    "window",
      "It is a dirty, cracked window.  Outside, you can see a trail\n"+
      "through an oak forest",
    "forest",
      "Through the window, you can see that it is full of trees",
    "trees",
      "Through the window, you can see that they are mostly oak",
    "tree",
      "Through the window, you can see that some seem to be sturdy redwood",
    "trails",
      "Through the window, you can see that they seem to be somewhat\n"+
      "clear paths between the trees",
    "trail",
      "Through the window, you can see that it seems to be a somewhat"+
      "clear path between the trees",
    "door",
      "It is made from warped pine boards.  It looks like it will "+
      "open easily",
    });
  dest_dir=({
             "players/nooneelse/entryforest/e_forest2", "leave",
           });
  if (!find_living("fred")) {
    woodsmith_obj=clone_object("players/nooneelse/mon/woodsmith");
    move_object(woodsmith_obj, this_object());
  }
}
