inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tOff in the distance (as far as you can tell) you see an Oofa\n"+
"  buckle and fold in the wake of a stampede of Boofers. Interesting.\n"+
"  Wait. Those Boofers are headed YOUR way!\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/boofer.c",
    "players/mizan/etheriel/beasties/fuzzle.c",
    "players/mizan/etheriel/beasties/mboofer.c"
  });
  ::extra_reset();
}
