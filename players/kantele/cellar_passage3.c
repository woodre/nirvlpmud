#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_short("In a dark passage");
  set_long(
"In a narrow twisting passage going south and north.\n");
  dest_dir = ({
    "players/kantele/cellar_passage2", "south"
  });
}
