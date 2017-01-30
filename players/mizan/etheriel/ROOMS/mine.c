inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tThe environment suddenly changes slightly, the multihued\n"+
"  swirls dull and fade into ially, and by now, your sense of time perception\n"+
"  has been confused to oblivion. You remain calm, however, realizing\n"+
"  that this is just another anomaly in the ether-muck, and that most of\n"+
"  organisms that call it home are not aggressive. MOST.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/mamie.c",
    "players/mizan/etheriel/beasties/fuzzle.c",
    "players/mizan/etheriel/beasties/something.c",
    "players/mizan/etheriel/beasties/light-bulb.c"
  });
  ::extra_reset();
}
