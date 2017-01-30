inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tA dazzling array of colors flashes before your eyes, and the\n"+
"  next thing you know, you have been caught up and fungled in a massive\n"+
"  shockwave of some sort. It seems that of all the things in this realm,\n"+
"  the only thing that truly terrifies you are the explosions that occur\n"+
"  every once in a while. Completely unpredictable in appearances, they\n"+
"  all share the common ground of having some sort of shockwave or tremor\n"+
"  force to back them up in the end.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/fungoid",
    "players/mizan/etheriel/beasties/colin.c",
    "players/mizan/etheriel/beasties/cactus.c",
    "players/mizan/etheriel/beasties/lost-wombat.c",
    "players/mizan/etheriel/beasties/light-bulb.c"
  });
  ::extra_reset();
}
