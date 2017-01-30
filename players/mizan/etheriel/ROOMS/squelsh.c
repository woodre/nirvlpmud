inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tDesperately reaching for what you comprehend as a human hand,\n"+
"  you get a handful of ether-goo instead. The apparition fades to reveal\n"+
"  a Boofer, which apparently read your thoughts and imitated them.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/blinking-boofer.c",
    "players/mizan/etheriel/beasties/spuckball.c",
    "players/mizan/etheriel/beasties/spud.c"
  });
  ::extra_reset();
  if(1==random(1000)) {
  move_object(clone_object("players/mizan/etheriel/heals/herring.c"), this_object());
  }
}
