#pragma strong_types

inherit "room/room";

int found;

void populate();

void
reset(status arg) {
  ::reset(arg);
  populate();
  if (arg)
    return;
  set_short("A small dirty room");
  set_long(
"This is a small dirty room, with lots of strange rubble.\n");
  dest_dir = ({
    "players/kantele/kitiaras_livingroom", "west"
  });
  items = ({
    "rubble", "A pile of rocks laying on the ground"
  });
}

void
populate() {
  found = 0;
}

void
init() {
  ::init();
  add_action("search_rubble", "search");
}

status
search_rubble(string arg) {
  object drink;
  if (arg == "rubble") {
    if (!found) {
      found = 1;
      drink = clone_object("obj/drink");
      drink->set_value(
"potion#A bottle with strange contents#You are totally healed#1000#500#0");
      move_object(drink, this_object());
      write("You found a strange bottle.\n");
      return 1;
    }
    else {
      write("You found nothing.\n");
      return 1;
    }
  }
  return 0;
}
