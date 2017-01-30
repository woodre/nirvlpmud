inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tGetting tossed and swirled around with creatures of questionable\n"+
"  origins and composition may be fun for some individuals, but it is \n"+
"  definitely an an aquired taste. Well. You are having fun, right?\n";
}

extra_reset() {
  object_names=({
  "players/mizan/etheriel/beasties/kerokerokeroppi.c",
  "players/mizan/etheriel/beasties/boink.c",
  "players/mizan/etheriel/beasties/leonard.c"
  });
  ::extra_reset();
}
