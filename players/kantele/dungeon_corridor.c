#pragma strong_types

inherit "room/room";

void reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_light(0);
  set_short("A dungeon corridor");
  set_long(
"A dungeon corridor, you can enter the watch room to the north and in the\n"+
"other directions there are celldoors.\n");
  dest_dir = ({
    "players/kantele/guard_room.c" ,"north",
    "players/kantele/cell1", "south",
    "players/kantele/cell2", "east",
    "players/kantele/cell3", "west",
  });
  items = ({
    "celldoor", "The celldoors are made of steel and look very tough",
  });
}

void init() {
  ::init();
  add_action("gate_check", "south");
  add_action("gate_check", "east");
  add_action("gate_check", "west");
  add_action("open_door", "open");
  add_action("open_door", "unlock");
}

status open_door(string str) {
  if (str == "door" || str == "celldoor") {
    write("There doesn't seem to be anyway to do that.\n");
    return 1;
  }
  return 0;
}

status gate_check() {
  switch(query_verb()) {
    case "south":
      if ("players/kantele/guard_room"->query_gate1()) {
        write("The celldoor is closed.\n");
        return 1;
      }
      this_player()->move_player("south#players/kantele/cell1");
      return 1;
      break;
    case "east":
      if ("players/kantele/guard_room"->query_gate2()) {
        write("The celldoor is closed.\n");
        return 1;
      }
      this_player()->move_player("east#players/kantele/cell2");
      return 1;
      break;
    case "west":
      if ("players/kantele/guard_room"->query_gate3()) {
        write("The celldoor is closed.\n");
        return 1;
      }
      this_player()->move_player("west#players/kantele/cell3");
      return 1;
      break;
    default:
      break;
  }
  return 0; /* Rumplemintz */
}
