#pragma strong_types

inherit "room/room";

int moved;

void populate();

void
reset(status arg) {
  ::reset(arg);
  populate();
  if (arg)
    return;
  set_short("You are in a large dark hall");
  set_long(
"You are in a large dark hall, you can enter the stairway to the west.\n"+
"Some barrels are lying against the north wall.\n");
  dest_dir = ({
    "players/kantele/stairway_down", "west",
  });
  items = ({
    "barrels", "Some barrels are lying against the north wall"
  });
}

void
populate() {
  moved = 0;
  remove_exit("players/kantele/cellar_passage");
  set_long(
"You are in a large dark hall, you can enter the stairway to the west.\n"+
"Some barrels are lying against the north wall.\n");
  remove_item("barrels");
  add_item("barrels", "Some barrels are lying against the north wall");
  ::init();
}

void
init() {
  ::init();
  add_action("barrel_move", "move");
}

status
barrel_move(string arg) {
  if (arg == "barrel" || arg == "barrels") {
    if (this_player()->query_level() < 14) {
      write("You are not strong enough to move the barrels.\n");
      say(this_player()->query_name()+
        " tries to move the barrels, but fails.\n");
      return 1;
    }
    write("You move the barrels to reveal a secret passage leading north.\n");
    moved = 1;
    say(this_player()->query_name() + " moves some of the barrels.\n");
    add_exit("players/kantele/cellar_passage", "north");
    remove_item("barrels");
    add_item("barrels","Some barrels are lying here");
    set_long(
"You are in a large dark hall, you can enter the stairway to the west.\n"+
"Some barrels are lying here, you can see a small black hole to the north.\n");
    ::init();
    return 1;
  }
}

