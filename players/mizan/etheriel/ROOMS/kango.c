inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tBewildered and befoggled, entropy and 'controlled' chaos\n"+
"  is the name of the game here. You suddenly feel a bit more lost and\n"+
"  confused than usual. Expected, right?\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/hagbard.c",
    "players/mizan/etheriel/beasties/colormonger.c",
    "players/mizan/etheriel/beasties/psychotic-barney.c",
    "players/mizan/etheriel/beasties/snorri.c"
  });
  ::extra_reset();
}
