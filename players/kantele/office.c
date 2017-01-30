#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_light(1);
  set_short("Dusty office");
  set_long(
"You are in a very dusty office, the only exit is to the north.\n");
  dest_dir = ({
    "players/kantele/trophy_room", "north"
  });
}
