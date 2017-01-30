#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_light(1);
  set_short("A landing in stairway");
  set_long(
"You are in a landing on the stairway, the stairway goes up\n" +
"and it disapears down into the darkness, an passage leads north.\n");
  dest_dir = ({
    "players/kantele/inner_hall", "north",
    "players/kantele/stairway_up", "up",
    "players/kantele/stairway_down", "down"
  });
}
