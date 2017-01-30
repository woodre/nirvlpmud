inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tTo believe everything that you see and hear is foolish. \n"+
"  Likewise, to an extent, the same rule applies here. Light and sound\n"+
"  take on whole new meanings here, since you do not see them following\n"+
"  any rule you know of modern physics. Not even the 'current' is steady,\n"+
"  sometimes feeling normal, but at other times defying natural instances\n"+
"  by tugging or pulling you in different directions at the same time.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/grimpo.c",
    "players/mizan/etheriel/beasties/oofa.c",
    "players/mizan/etheriel/beasties/herman.c"
  });
  ::extra_reset();
}
