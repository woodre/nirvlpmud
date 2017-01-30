#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_short("you are in a small room");
  set_long(
"You are in a small room, there is a stairway to the north and some sort\n"+
"of a temple to the south.\n");
  dest_dir = ({
    "players/kantele/dirty_stairway", "north",
    "players/kantele/dirty_temple", "south"
  });
}
