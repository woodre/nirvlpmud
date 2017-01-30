#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_short("You are in a narrow corridor");
  set_long(
"You are in a narrow corridor, it is damp and dark.\n");
  dest_dir = ({
    "players/kantele/cellar_west", "south",
    "players/kantele/dirty_corridor", "north"
  });
}
