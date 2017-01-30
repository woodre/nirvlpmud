#pragma strong_types

inherit "room/room";

void populate();

int open, locked;

void
reset(status arg) {
  ::reset(arg);
  populate();
  if (arg)
    return;
  set_light(1);
  set_short("You are in Kitiaras anteroom");
  set_long(
"You are in Kitiaras anteroom, a sturdy steal door leads west\n"+
"and a passage east. There is a sign on the door.\n");
  dest_dir = ({
    "players/kantele/cellar_west", "east",
    "players/kantele/kitiaras_hall", "west"
  });
  items = ({
    "sign", "there is a sign on the door, the sign says\n"+
            "MORTALS SHOULD NOT ENTER !(on pain of death)",
    "door", "The door is closed"
  });
}
  
void
populate() {
  open = 0;
  locked = 1;
  remove_item("door");
  add_item("door", "The door is closed");
}

void
init() {
  ::init();
  add_action("open", "open");
  add_action("unlock", "unlock");
  add_action("west", "west");
}

status
open(string str) {
  if (str && str != "door")
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
  write("You open the door.\n");
  say(this_player()->query_name()+ " opened the door.\n");
  remove_item("door");
  add_item("door", "The door is open");
  "players/kantele/kitiaras_hall"->remove_item("door");
  "players/kantele/kitiaras_hall"->add_item("door", "The door is open");
  return 1;
}

status
unlock(string str) {
  if (str && str != "door")
    return 0;
  if (open || !locked) {
    write("The door is not locked.\n");
    return 1;
  }
  if (!present("mansion key", this_player())) {
    write("You do not have the right key.\n");
    return 1;
  }
  locked = 0;
  write("You unlock the door.\n");
  say(this_player()->query_name()+ " unlocked the door.\n");
  return 1;
}

status
west() {
  if (!open) {
    write("The door is closed.\n");
    return 1;
  }
  return 0;
}

status query_door() { return !open; }

void
open_door_inside() {
    locked = 0;
    open = 1;
    remove_item("door");
    add_item("door", "The door is open");
}
