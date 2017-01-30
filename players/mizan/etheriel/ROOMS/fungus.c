inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tWhat a strange place! The color seems to be a bit more intense here \n"+
"  for some reason... aha.. It must be because of the two things circling your\n"+
"  head.. no, wait, they just passed through it.\n";
}

extra_reset() {
  object_names=({
  "players/mizan/etheriel/beasties/oofa.c",
  "players/mizan/etheriel/beasties/oofa.c",
    "players/mizan/etheriel/beasties/spuckball-b",
  "players/mizan/etheriel/beasties/fuzzy.c",
  "players/mizan/etheriel/environs/faucet.c"
  });
  ::extra_reset();
}
