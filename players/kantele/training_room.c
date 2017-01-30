#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_light(1);
  set_short("training room");
  set_long(
"You are in a training room.\n");
  dest_dir = ({
    "players/kantele/small_room", "north",
    "players/kantele/knights_room", "west"
  });
}
