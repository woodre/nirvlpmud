#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_light(1);
  set_short("Behind the bar");
  set_long(
"You are behind the bar, you can enter the barroom proper to the\n"+
"west, there is a very large barrel of beer here, there should be\n"+
"possible to drink from the tap.....\n");
  dest_dir = ({
    "players/kantele/bar", "east"
  });
}

void
init() {
  ::init();
  add_action("drink_beer", "drink");
}

status
drink_beer(string str) {
  if (str != "from tap" && str != "from the tap")
    return 0;
  if (this_player()->drink_alcohol(2)) {
    write("It tasted a bit stale\n");
  }
  return 1;
}
