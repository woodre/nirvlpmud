#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_light(1);
  set_short("In the robing room");
  set_long(
"In a small robing room, tho the east you can see the altar.\n");
  dest_dir = ({
    "players/kantele/behind_altar", "east"
  });
}
