inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tThe origins of the funky material that you are 'swimming' in\n"+
"  is a complete and utter mystery to you. It is not of uniform\n"+
"  consistency, and you get bungled easily as you drift from a smooth area\n"+
"  to a dense one.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/environs/disclaimer_to_amy.c",
    "players/mizan/etheriel/beasties/snorri.c",
    "players/mizan/etheriel/beasties/blinking-oofa.c",
    "players/mizan/etheriel/beasties/spuckball.c"
  });
  ::extra_reset();
  if(1==random(1600)) {
  move_object(clone_object("players/mizan/etheriel/heals/twinkie.c"), this_object());
  }
}
