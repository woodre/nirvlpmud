/*
 groad35.c - good side of green road
*/

inherit "room/room";

string str, str2;

object nymph, coins;

init() {
  ::init();

  add_action("swim",  "swim");
  add_action("swim",  "dive");
  add_action("swim",  "enter");
  add_action("drink", "drink");
}

swim(str) {
  if (!str) {
    write("In what?\n");
    return 1;
  }
  sscanf(str, "in %s", str2);
  if (str && str=="water" || str=="pool" || str2=="water" || str2=="pool") {
    write("A strong current carries you deeper and deeper into the water!\n"+
          "You swim harder than ever before, you feel like you'll drown!\n"+
          "Just when your lungs feel like they'll burst, you surface.\n\n");
    call_other("players/nooneelse/green/groad31", "???", 0);
    move_object(this_player(), "players/nooneelse/green/groad31");
    command("look", this_player());
    return 1;
  }
}

drink(str) {
  if (str && str=="water") {
    write("You drink deeply.  It's clean and refreshing.\n");
    say(this_player()->query_name()+" drinks from the pool.\n");
    return 1;
  }
}

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc=("a pretty path");
  no_castle_flag=1;
  long_desc="You are standing on a path in a pretty forest.  "+
            "You sense good everywhere.\n"+
            "There is a large pool of water here.\n";
  items =
    ({
      "forest", "It is a dense forest.  The trees are too close together for\n"+
                "you to go anywhere except on the path.",
      "path", "It is a narrow, clear path.",
      "trees", "The trees are strong and healthy.  "+
               "The ground is covered with soft grass.",
      "tree", "The tree is strong and healthy.  "+
              "The ground is covered with soft grass.",
      "grass", "The grass is long, soft and comforatable to walk on.",
      "pool", "The water is clean and clear, but you can't see the bottom.",
      "water", "The water is clean and clear, but you can't see the bottom.",
    });
  dest_dir=
    ({
      "players/nooneelse/green/groad36", "west",
      "players/nooneelse/green/groad34", "east",
    });
  if (!find_living("nymph")) {
    move_object(clone_object("players/nooneelse/mon/nymph"), this_object());
  }
  return;
}
