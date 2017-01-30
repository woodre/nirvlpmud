#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_light(1);
  set_short("Entrance hall");
  set_long(
"You are in the entrance hall to the mansion, a door leads \n"+
"north and a passage leads south.\n");
  dest_dir = ({
    "players/kantele/inner_hall", "south",
    "players/kantele/inner_courtyard", "north"
  });
  items = ({
    "door", "The door is closed"
  });
}

void
init() {
  ::init();
  add_action("north_check", "north");
  add_action("open_door", "open");
}

status
north_check() {
  if ("players/kantele/inner_courtyard"->query_door()) {
    write("The door is closed.\n");
    return 1;
  }
  return 0;
}

status
open_door(string str) {
  if (!str || str != "door")
    return 0;
  if (!("players/kantele/inner_courtyard"->query_door())) {
    write("It is already open!\n");
    return 1;
  }
  "players/kantele/inner_courtyard"->open_door_inside();
  write("You open the door.\n");
  say(this_player()->query_name()+" opens the door.\n");
  return 1;
}

