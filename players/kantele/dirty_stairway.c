#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_short("You are in a stairway");
  set_long(
"You are at the bottom of a stairway, you can go up or enter\n"+
"a small room to the south.\n");
  dest_dir = ({
    "players/kantele/dirty_anteroom", "south",
    "players/kantele/dirty_corridor", "up"
  });
}
