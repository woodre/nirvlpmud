#pragma strong_types

inherit "room/room";

int search_flag;

void
reset(status arg) {
  search_flag = 0;
  if (arg)
    return;
  set_light(1);
  short_desc = "In a ditch";
  long_desc = 
"You are in a ditch.  Get up, you are making yourself dirty!\n";
  dest_dir = ({
    "players/angmar/fairyland/corn1", "west",
    "players/angmar/fairyland/meadow", "east",
  });
  items = ({
    "ditch", "It's filled with mud, dirt, and water",
    "mud", "There's nothing to be found in the mud",
    "dirt", "It does nothing but get your armor dirty",
    "water", "It does nothing but ruin your weapons",
  });
}

string realm() { return ("fairyland"); }

void
init() {
  room::init();
  add_action("drink", "drink");
  add_action("Search", "search");
}

status
drink(string str) {
  if (!str)
    return 0;
  if (str != "water")
    return 0;
  write("You cup your hands for some water, and notice some blood in the water.\n");
  write ("You decide not to drink it.\n");
  say(this_player()->query_name() + 
      " prepares to drink some water, but thinks better of it.\n");
  return 1;
}

status
Search(string str) {
  if (!str || str != "ditch") {
    write ("What?\n");
    return 1;
  }
  if (!search_flag) {
    write("You find a piece of candy in the ditch!\n");
    say(this_player()->query_name() + 
        " finds something in the ditch.\n");
    move_object(clone_object("players/angmar/o/candy"), this_object());
    search_flag = search_flag + 1;
    return 1;
  }
  write ("You don't find anything.\n");
  say(this_player()->query_name() + " searches the ditch to no avail.\n");
  return 1;
}
