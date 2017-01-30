#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_light(1);
  set_short("A small courtyard");
  set_long(
"A small courtyard, a road leads north, to the east you can see \n" +
"a small shack. to the west a small open wagon stall can be seen \n" +
"while to the south the entrance to the mansion can be seen \n");
  dest_dir = ({
    "players/kantele/brick_road", "north",
    "players/kantele/shack", "east",
    "players/kantele/wagon_stall", "west",
    "players/kantele/inner_courtyard", "south"
  });
}
