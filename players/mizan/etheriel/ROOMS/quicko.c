inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tPokey globs of blue goo drift by, in a semi-organized manner\n"+
"  like a school of fish. You are boggled by the way they seem to act in\n"+
"  unison, and are left with an uneasy feeling in your stomach for some\n"+
"  reason. Hmm. It could be that disemboweled rodent that just floated\n"+
"  past you.\n";
}

query_zokko() { return "ASDFSDFSDF"; }

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/exploding-mac.c",
    "players/mizan/etheriel/environs/funky-door.c",
    "players/mizan/etheriel/beasties/symidryl.c",
    "players/mizan/etheriel/beasties/tunafish.c",
    "players/mizan/etheriel/beasties/bleh.c"
  });
  ::extra_reset();
  if(1==random(4)) {
  move_object(clone_object("players/mizan/etheriel/beasties/hoojib.c"), this_object());
  }
}

