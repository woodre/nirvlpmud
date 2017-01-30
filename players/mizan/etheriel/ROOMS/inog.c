inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tThat blob of something that flew through your stomach suddenly\n"+
"  cured your hunger, effectively making you lose your appetite. Blah.\n"+
"  The ether-mucky-stuff you are floating in is rather turbulent here,\n"+
"  not just in a 'physical' way but you are having a hard time thinking\n"+
"  which way to go.\n";
}

extra_reset() {
  object_names=({
  "players/mizan/etheriel/beasties/spuckball-b",
  "players/mizan/etheriel/beasties/flytrap.c",
  "players/mizan/etheriel/beasties/spucktrooper.c",
  "players/mizan/etheriel/beasties/wahgo.c",
  "players/mizan/etheriel/environs/panic-button.c"
  });
  ::extra_reset();
}
