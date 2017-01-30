/*
  e_forest11.c
*/

inherit "room/room";

realm() { return "NT"; }

reset(arg) {
  if (arg) return 0;

  set_light(1);
  short_desc="A dark forest";
  long_desc="You are in part of a dark forest.  An erie mist seems to be\n"+
           "boiling along the ground.\n";
  items=({
         "forest", "It is full of trees",
         "trees", "They are mostly oak",
         "tree", "This one seems to be a sturdy redwood",
         "trails",
             "They seem to be somewhat clear paths between the trees",
         "trail",
             "It seems to be a somewhat clear path between the trees",
         "mist",
             "It seems to be a strange violet mist.  Warm instead of\n"+
             "chilly.  Perhaps you could enter it",
          });
  dest_dir=({
             "players/nooneelse/entryforest/e_forest10", "east",
          });
}

init() {
  ::init();

  add_action("enter", "enter");
}

enter(arg) {
  string my_name_cap;
  if (!arg || arg != "mist") return 0;
  say(this_player()->query_name()+" disappears into the mist.\n",
      this_player());
  write("You walk slowly into the mist.\n");
  this_player()->move_player("X#/players/nooneelse/mist");
  return 1;
}
