#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_short("A small dark hall");
  set_long(
"You are in a small dark hall, a pasage leads south and a\n"+
"door leads east, you can see some light to the south.\n");
  dest_dir = ({
    "players/kantele/kitiaras_crossing", "south",
    "players/kantele/kitiaras_anteroom", "east"
  });
  items = ({
    "door", "The door is closed"
  });
}

void
init() {
  ::init();
  add_action("east", "east");
  add_action("open", "open");
}

status
east() {
  if ("players/kantele/kitiaras_anteroom"->query_door()) {
    write("The door is closed.\n");
    return 1;
  }
  return 0;
}

status
open(string str) {
  if (str == "door") {
    if (!"players/kantele/kitiaras_anteroom"->query_door()) {
      write("It is already open!\n");
      return 1;
    }
    "players/kantele/kitiaras_anteroom"->open_door_inside();
    remove_item("door");
    add_item("door", "The door is open");
    write("You open the door.\n");
    say(this_player()->query_name()+ " opened the door.\n");
    return 1;
  }
  return 0;
}
