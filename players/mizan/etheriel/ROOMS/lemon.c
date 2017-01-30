inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tDrifting into this area you see more strange beasties, floating \n"+
"  around, not doing much of anything besides disappearing and reappearing.\n"+
"  One of them, however, is very different... (It's bigger!)\n";
}

extra_reset() {
  object_names=({
  "players/mizan/etheriel/environs/spigot.c",
  "players/mizan/etheriel/beasties/mad_hunter.c",
  "players/mizan/etheriel/beasties/boofer.c",
  "players/mizan/etheriel/beasties/grimpo.c",
  "players/mizan/etheriel/beasties/grimpo.c"
  });
  ::extra_reset();
}
