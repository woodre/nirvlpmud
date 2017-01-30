inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tFolding beams of light scatter and play in front of you. Lobes\n"+
"  of brightly colored balloon-like things hang around the place, as well\n"+
"  as an odd looking individual. The lobes disappear within themselves, and\n"+
"  reappear out of nowhere. \n";
}

extra_reset() {
  object_names=({
  "players/mizan/etheriel/beasties/spuckball-b.c",
  "players/mizan/etheriel/beasties/bunupuradah.c",
  "players/mizan/etheriel/beasties/grimpo.c",
  "players/mizan/etheriel/beasties/oofa.c",
  "players/mizan/etheriel/environs/puddle.c"
  });
  ::extra_reset();
}
