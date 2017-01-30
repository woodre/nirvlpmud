#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_short("The second floor hall");
  set_long(
"You are in the hall on the second floor, to the north you can\n"+
"exit on to the roof. to the south you can see the stairway.\n");
  dest_dir = ({
    "players/kantele/on_roof", "north",
    "players/kantele/lab", "west",
    "players/kantele/small_room", "east",
    "players/kantele/stairway_up", "south"
  });
}
