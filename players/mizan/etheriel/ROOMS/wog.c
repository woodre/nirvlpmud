inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tYou are squishing around in this ether-muck and it is starting\n"+
"  become very frustrated. Perhaps it is simply the fact that the\n"+
"  colors here are not as radiant and mumsy as in other spots. Perhaps it\n"+
"  is that the creatures here are not as friendly, as the majority of\n"+
"  them float away in panic after detecting your presence. Who knows...\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/environs/panic-button",
    "players/mizan/etheriel/environs/trivial-fact.c",
    "players/mizan/etheriel/items/quick-score.c",
    "players/mizan/etheriel/beasties/toaster.c",
    "players/mizan/etheriel/beasties/spuckball.c"
  });
  ::extra_reset();
}
