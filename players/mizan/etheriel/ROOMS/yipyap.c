inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tYou are convinced that an absence of solid objects in this\n"+
"  realm would make things MUCH more fun. The ability to cruise at\n"+
"  blistering speeds with minimal thought control would be possible,\n"+
"  without worrying about crashing into a toilet bowl, a tree, roadsigns,\n"+
"  or even lampshades for that matter...\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/sarawak.c",
    "players/mizan/etheriel/beasties/bullfrog.c",
    "players/mizan/etheriel/environs/chall-button.c",
    "players/mizan/etheriel/beasties/lost-wombat.c"
  });
  ::extra_reset();
}
