#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_short("A beautiful garden");
  set_long(
"A beautiful garden, in the middle of the garden you can see a\n"+
"small pool, you can see some goldfishes swimming around \n");
  dest_dir = ({
    "players/kantele/brick_road", "west",
    "players/kantele/pool", "enter",
    "players/kantele/courtyard", "south"
  });
}
