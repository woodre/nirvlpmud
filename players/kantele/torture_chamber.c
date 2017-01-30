#pragma strong_types

inherit "room/room";

int iron_maiden;

void populate();

void reset(status arg) {
  ::reset(arg);
  populate();
  if (arg)
    return;
  set_short("In a torture chamber");
  set_long(
"In a torture chamber, the only exit is east into the guardroom. You\n"+
"can see a well used stretch bench and an iron maiden.\n");
  dest_dir = ({
    "players/kantele/guard_room", "east"
  });
  items = ({
    "iron maiden", "The iron maiden is closed"
  });
}

void populate() {
  iron_maiden = 0;
  remove_item("iron maiden");
  add_item("iron maiden", "The iron maiden is closed");
}

void init() {
  ::init();
  add_action("enter", "enter");
  add_action("open_maiden", "open");
}

status open_maiden(string str) {
  if (str == "iron maiden") {
    if (iron_maiden) {
      write("The iron maiden is already open.\n");
      return 1;
    }
    write("You open the iron maiden.\n");
    say(this_player()->query_name()+" opens the iron maiden.\n");
    iron_maiden = 1;
    remove_item("iron maiden");
    add_item("iron maiden", "The iron maiden is open");
    return 1;
  }
  return 0;
}

status enter(string str) {
  if (str == "iron maiden") {
    write("You can't do a so stupid thing.......\n");
    say(this_player()->query_name()+ " thinks " +
        this_player()->query_pronoun()+" is playing ABERmud.\n");
    return 1;
  }
  return 0;
}
