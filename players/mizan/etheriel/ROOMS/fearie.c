inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tLaunched by a passing Boofer into the confines of a plasma-\n"+
"  like 'bubble', gravity and some of the other forces of nature return.\n"+
"  You hate it. You were getting used to the consistent inconsistency that\n"+
"  this odd place offers. With a solid kick, you break free of the 'bubble'\n"+
"  and are set free into the swirling ether-muck environment again.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/mean-spuckball.c",
    "players/mizan/etheriel/beasties/mog.c",
    "players/mizan/etheriel/beasties/colormonger3.c"
  });
  ::extra_reset();
}
