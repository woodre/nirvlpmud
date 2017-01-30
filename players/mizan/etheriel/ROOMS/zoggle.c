inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tA small vortex suddenly appears, swirling rapidly and making\n"+
"  funny 'popping' sounds. It leaves in its wake a strong current, potent\n"+
"  enough to make you start spinning slowly. Then, with the blink of an\n"+
"  eye, it vanishes with a *poof*.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/snurfle.c",
    "players/mizan/etheriel/beasties/ziggle.c",
    "players/mizan/etheriel/beasties/ettin.c"
  });
  ::extra_reset();
  if(1==random(110)) {
  move_object(clone_object("players/mizan/etheriel/heals/twinkie.c"), this_object());
  }
}
