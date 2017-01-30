#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_light(1);
  set_short("A dusty room, with a pentagram");
  set_long(
"A dusty room, you can see a small pentagram chalked up in the \n"+
"dirt. you can exit west into the hall or south into the trainging room\n");
  dest_dir = ({
    "players/kantele/training_room", "south",
    "players/kantele/upper_hall", "west"
  });
}
