#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_short("You are in a dirty passage");
  set_long(
"You are in a dirty passage, a stairway leads down and the \n"+
"corridor continues to the north.\n");
  dest_dir = ({
    "players/kantele/dirty_passage", "south",
    "players/kantele/dirty_stairway", "down",
    "players/kantele/dirty_room", "north"
  });
}
