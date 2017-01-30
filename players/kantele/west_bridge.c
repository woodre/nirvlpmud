#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  ::reset(arg);
  
  if (arg)
    return;
  
  set_short("You are in a hall");
  set_long(
"You are in a hall, exits leads off in every direction\n" +
"to the east you can see a rotten wooden bridge.\n");
  dest_dir = ({
    "/players/kantele/sphinx_room", "south",
    "/players/kantele/hellgate_anteroom", "north",
    "/players/kantele/guard_room", "west",
    "/players/kantele/on_bridge", "east"
  });
}
