#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_light(1);
  set_short("Kantele's workroom");
  set_long(
"You are in Kanteles workroom, a large oak desk covers most of the\n"+
"room, you can go north into the lab or east into a small room.\n" +
"you can se a massive oak dest against the wall.\n");
  dest_dir = ({
    "players/kantele/lab", "north",
    "players/kantele/knights_room", "east"
  });
}
