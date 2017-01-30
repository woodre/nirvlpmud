#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_short("A beautiful garden");
  set_long(
"A beautiful garden filled with strange flowers of many exotic\n"+
"flowers. Some strange trees lines the fence \n");
  dest_dir = ({
    "players/kantele/brick_road", "east",
    "players/kantele/courtyard", "south"
  });
}
