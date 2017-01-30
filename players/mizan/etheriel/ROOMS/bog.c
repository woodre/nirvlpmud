inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\t'Aaaaaauuuugh!' you scream as something painful digs into\n"+
  "  the fleshy part of your hand... you turn it over to examine\n"+
  "  it but see nothing... Intense.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/bugs.c",
    "players/mizan/etheriel/beasties/cactus.c",
    "players/mizan/etheriel/beasties/symidryl.c",
    "players/mizan/etheriel/subrealms/beating_council/castle.c",
  });
  ::extra_reset();
}
