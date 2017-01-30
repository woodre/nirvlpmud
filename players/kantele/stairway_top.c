#pragma strong_type

inherit "room/room";

void
reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_light(1);
  set_short("You are on the upper landing");
  set_long(
"You are on a landing in the stairway, this place gives you \n"+
"a bad feeling, you feel truley depresed at the thought of \n"+
"going further up the stairway.\n");
  dest_dir = ({
    "players/kantele/stairway_up", "down",
    "players/kantele/snake_pit", "up"
  });
}

void
init() {
  ::init();
#ifndef __LDMUD__ /* Rumplemintz */
  add_action("up"); add_verb("up");
#else
  add_action("up", "up");
#endif
}

status
up() {
  write("As you start to walk up the stair, A pit opens under your feet\n");
  write("You fall, down into the pit.........\n\n\n\n");
  return 0;
}
