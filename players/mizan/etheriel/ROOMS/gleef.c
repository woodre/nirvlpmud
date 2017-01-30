inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tIt is WAY too quiet around here... you wonder why...\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/environs/exploder.c"
  });
  ::extra_reset();
  if(1==random(1000)) {
  move_object(clone_object("players/mizan/etheriel/environs/ladyl.c"), this_object());
  }
}
