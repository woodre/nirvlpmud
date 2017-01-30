#pragma strong_types

inherit "room/room";

int open, locked;

void populate();

void
reset(status arg) {
  ::reset(arg);
  populate();
  if (arg)
    return;
  set_light(1);
  set_short("The inner courtyard");
  set_long(
"You are in the inner courtyard, it opens up to the north \n" +
"and a door leads south. there is a sign on the door.\n");
  dest_dir = ({
    "players/kantele/courtyard", "north",
    "players/kantele/hall", "south"
  });
  items = ({
    "sign", "The sign says\nKantele lives here, beware",
    "door", "The door is closed"
  });
}

void
populate() {
  open = 0;
  locked = 1;
}

void
init() {
  ::init();
  add_action("open_door", "open");
  add_action("close_door", "close");
  add_action("unlock_door", "unlock");
  add_action("lock_door", "lock");
  add_action("south_check", "south");
}

status
open_door(string str) {
  if (!str || str != "door")
    return 0;
  if (open) {
    write("The door is already open.\n");
    return 1;
  }
  if (locked) {
    write("The door is locked.\n");
    return 1;
  }
  open = 1;
  remove_item("door");
  add_item("door", "The door is open");
  "players/kantele/hall"->remove_item("door");
  "players/kantele/hall"->add_item("door", "The door is open");
  write("You open the door.\n");
  say(this_player()->query_name()+" opens the door.\n");
  return 1;
}

status
close_door(string str) {
  if (!str || str != "door")
    return 0;
  if (!open) {
    write("The door is not open.\n");
    return 1;
  }
  open = 0;
  remove_item("door");
  add_item("door", "The door is closed");
  "players/kantele/hall"->remove_item("door");
  "players/kantele/hall"->add_item("door", "The door is closed");
  write("You close the door.\n");
  say(this_player()->query_name()+" closes the door.\n");
  return 1;
}

status
unlock_door(string str) {
  if (!str || str != "door")
    return 0;
  if (open || !locked) {
    write("The door is not locked.\n");
    return 0;
  }
  if (!present("mansion key", this_player())) {
    write("You do not have the correct key.\n");
    return 1;
  }
  locked = 0;
  write("Click!\n");
  write("You unlock the door.\n");
  say(this_player()->query_name()+" unlocks the door.\n");
  return 1;
}

status
lock_door(string str) {
  if (!str || str != "door")
    return 0;
  if (open) {
    write("The door is open.\n");
    return 1;
  }
  if (locked) {
    write("The door is already locked.\n");
    return 1;
  }
  locked = 1;
  write("Click!\n");
  write("You lock the door.\n");
  say(this_player()->query_name()+" locks the door.\n");
  return 1;
}

status
south_check() {
  if (!open) {
    write("The door is closed.\n");
    return 1;
  }
  this_player()->move_player("south#players/kantele/hall");
  return 1;
}

int
query_door() {
  return !open;
}

void
open_door_inside() {
  locked = 0;
  open = 1;
  remove_item("door");
  add_item("door", "The door is open");
  "players/kantele/hall"->remove_item("door");
  "players/kantele/hall"->add_item("door", "The door is open");
}
