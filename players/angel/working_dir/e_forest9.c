/*
  e_forest9.c
*/

inherit "room/room";

realm() { return "NT"; }

reset(arg) {
  object nymph_obj;
  if (arg) return 0;

  set_light(1);
  short_desc="A dimly lit forest";
  long_desc="You are in part of a dimly lit forest.  Next to the path is a\n"+
           "deep pool of water.\n";
  items=({
         "pool",
           "The water is clean and clear, but you can't see the bottom",
         "water",
           "The water is clean and clear, but you can't see the bottom",
         "forest", "It is full of trees",
         "trees", "They are mostly oak",
         "tree", "This one seems to be a sturdy redwood",
         "trails",
           "They seem to be somewhat clear paths between the trees",
         "trail",
           "It seems to be a somewhat clear path between the trees",
       });
  dest_dir=({
             "players/nooneelse/entryforest/e_forest10", "north",
             "players/nooneelse/entryforest/e_forest6", "east",
             "players/nooneelse/entryforest/e_hills1", "south",
           });
  if (!find_living("nymph")) {
    nymph_obj=clone_object("players/nooneelse/mon/nymph");
    move_object(nymph_obj, this_object());
  }
}

init() {
  ::init();

  add_action("swim",  "swim");
  add_action("swim",  "dive");
  add_action("swim",  "enter");
  add_action("drink", "drink");
}

swim(str) {
  string str2;
  if (!str) {
    write("In what?\n");
    return 1;
  }
  if (present("nymph", this_object())) {
    write("The nymph stops you, saying:  Stay away from my water.\n");
    return 1;
  }
  if (present("nixie", this_object())) {
    write("The nixie stops you, saying:  Stay away from my water.\n");
    return 1;
  }
  str2=0;
  sscanf(str, "in %s", str2);
  if (!str2) sscanf(str, "into %s", str2);
  if (str=="water" || str=="pool" || str2=="water" || str2=="pool") {
    write("A strong current carries you deeper and deeper into the water!\n\n"+
          "You swim harder than ever before, you feel like you'll drown!\n\n"+
          "Just when your lungs feel like they'll burst, you surface.\n\n");
    this_player()->move_player("X#players/nooneelse/entryforest/e_forest4");
    return 1;
  }
  return 0;
}

drink(str) {
  if (!str || str != "water") return 0;
  if (present("nymph", this_object())) {
    write("The nymph stops you, saying:  Stay away from my water.\n");
    return 1;
  }
  if (present("nixie", this_object())) {
    write("The nixie stops you, saying:  Stay away from my water.\n");
    return 1;
  }
  write("You drink deeply.  It's clean and refreshing.\n");
  say(this_player()->query_name()+" drinks from the pool.\n", this_player());
  return 1;
}
