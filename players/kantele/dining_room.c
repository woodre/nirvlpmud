#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_light(1);
  set_short("Dining room");
  set_long(
"A beautiful dining room, this room is decorated with dark cedar \n" +
"panels, you can smell coking to the south.\n");
  dest_dir = ({
    "players/kantele/inner_hall", "east",
    "players/kantele/kitchen", "south"
  });
}
