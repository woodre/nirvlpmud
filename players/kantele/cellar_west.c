#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_short("You are in the west hall");
  set_long(
"You are in the west hall in the cellar, you can go east to the\n"+
"stairway, or follow passages north or west.\n");
  dest_dir = ({
    "players/kantele/stairway_down", "east",
    "players/kantele/kitiaras_anteroom", "west",
    "players/kantele/dirty_passage", "north"
  });
}
