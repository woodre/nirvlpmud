inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/grimpo.c",
    "players/mizan/etheriel/beasties/fuzzy.c",
    "players/mizan/etheriel/beasties/blinking-boofer.c"
  });
  ::extra_reset();
}
