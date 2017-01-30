inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tSomething rather large and unpleasantly solid makes its\n"+
"  presence here, and you are not too sure how to react to it. Being that\n"+
"  it is only large, solid, objects drifting around in the ether-muck,\n"+
"  there has to be something rather extraordinary about it. Then... maybe not.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/blinking-oofa.c",
    "players/mizan/etheriel/beasties/light-bulb",
    "players/mizan/etheriel/beasties/tunafish",
  });
  ::extra_reset();
  if(1==random(1000)) {
  move_object(clone_object("players/mizan/etheriel/heals/portable_cow.c"), this_object());
  }
}
