inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tWithout cause or reason, your chest begins to hurt. It must\n"+
"  have been those things that just flew through it a few moments ago.\n"+
"  With a violent cough, you spit up what appear to have been cotton balls.\n"+
"  Hindsight, being the mother of all learning, is very obvious in this case.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/spuckball.c",
    "players/mizan/etheriel/beasties/spuckball.c",
    "players/mizan/etheriel/beasties/vknight.c",
    "players/mizan/etheriel/beasties/vknight.c",
    "players/mizan/etheriel/beasties/sarawak.c",
    "players/mizan/etheriel/beasties/fuzzle.c"
  });
  ::extra_reset();
}
