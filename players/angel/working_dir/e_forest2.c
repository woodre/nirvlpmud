/*
  e_forest2.c
*/

inherit "room/room";

realm() { return "NT"; }

reset(arg) {
  if (arg) return 0;

  set_light(1);
  short_desc="A dimly lit forest";
  long_desc="You are in part of a dimly lit forest.  There is an old\n"+
            "log cabin beside the trail.\n";
  items=({
         "forest", "It is full of trees",
         "trees", "They are mostly oak",
         "tree", "This one seems to be a sturdy redwood",
         "trails",
           "They seem to be somewhat clear paths between the trees",
         "trail",
           "It seems to be a somewhat clear path between the trees",
         "cabin",
           "It looks like a one-room log cabin.  It has a shingle roof,\n"+
           "one window and a single door",
         "log cabin",
           "It looks like a one-room log cabin.  It has a shingle roof,\n"+
           "one window and a single door",
         "roof", "It is a peaked roof covered with shingles",
         "shingles", "They are made of pine bark",
         "shingle", "It is made of pine bark",
         "window",
           "It is a dirty, cracked window.  Inside, you can see a bed,\n"+
           "one chair and a small table",
         "door",
           "It is made from warped pine boards.  It looks like it will "+
           "open easily",
       });
  dest_dir=({
             "players/nooneelse/entryforest/e_forest3", "north",
             "players/nooneelse/entryforest/e_forest6", "west",
             "players/nooneelse/entryforest/e_forest1", "south",
          });
}

init() {
  ::init();

  add_action("enter", "enter");
}

enter(arg) {
  string my_name_cap;
  if (!arg) return 0;
  if (arg != "cabin" && arg != "log cabin") return 0;
  my_name_cap = capitalize(this_player()->query_name());
  write("The cabin's door squeaks as you push it open to enter.\n");
  say("The cabin's door squeaks as "+my_name_cap+
      " pushes it open and enters.\n", this_player());
  this_player()->move_player("X#players/nooneelse/entryforest/e_cabin");
  return 1;
}
