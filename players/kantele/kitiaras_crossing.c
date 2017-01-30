#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_light(1);
  set_short("You are in a crossing");
  set_long(
"You are in a crossing, a passage goes north/south and a exit\n"+
"leads east.\n");
  dest_dir = ({
    "players/kantele/kitiaras_hall", "north",
    "players/kantele/snake_room", "east",
    "players/kantele/kitiaras_innerhall", "south"
  });
}
