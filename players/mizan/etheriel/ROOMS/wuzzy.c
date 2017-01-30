inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tBeing more than slightly lost, you are now a bit more than slightly\n"+
"  confused, with this wall of jello floating before you. You are not quite\n"+
"  sure what it is doing here, and you decide to think about it...\n";
}

extra_reset() {
  object_names=({
  "players/mizan/etheriel/environs/jello-wall.c",
  "players/mizan/etheriel/beasties/something.c",
  "players/mizan/etheriel/beasties/spuckball.c",
  "players/mizan/etheriel/beasties/hoojib.c"
  });
  ::extra_reset();
}
