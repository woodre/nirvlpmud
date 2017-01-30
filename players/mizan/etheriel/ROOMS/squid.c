inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tHovering motionless for a bit, you gaze at the ever-changing\n"+
"  and contorting shapes in the backdrop around you. Far off in the deep\n"+
"  distance you see a party of adventurers being overcome by a Sarawak.\n"+
"  You begin to chuckle and giggle uncontrollably, then suddenly erupt into\n"+
"  a ravenous laughter. You sicko.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/explodey",
    "players/mizan/etheriel/beasties/fuzzle.c",
    "players/mizan/etheriel/beasties/spud.c",
    "players/mizan/etheriel/environs/spuggle-machine.c"
  });
  ::extra_reset();
  if(1==random(1000)) {
  move_object(clone_object("players/mizan/etheriel/environs/wz-pinball.c"), this_object());
  }
}
