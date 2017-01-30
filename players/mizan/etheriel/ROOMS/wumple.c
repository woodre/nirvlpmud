inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tYou are squishing around in this ether-muck and it is starting to\n"+
"  make you somewhat depressed. Perhaps it is simply the fact that the\n"+
"  colors here are not as radiant and mumsy as in other spots. Perhaps it\n"+
"  is that the creatures here are not as friendly, as the majority of\n"+
"  them float away in panic after detecting your presence. Who knows...\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/tacoban2.c",
    "players/mizan/etheriel/beasties/harry.c",
    "players/mizan/etheriel/beasties/boink.c",
    "players/mizan/etheriel/beasties/cactus.c"
  });
  ::extra_reset();
}
