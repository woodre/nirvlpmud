inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tAnother explosion 'far' in the distance has reached your\n"+
"  eyes and ears, and successfully chilling your nerves. You are left in\n"+
"  a mild fuzzlement about why these explosions occur, since the realm\n"+
"  is wracked by them quite often. Judging from most of the creatures that\n"+
"  inhabit this realm, they are _not_ a naturally occuring part of this\n"+
"  world. Something or someone from somewhere else is causing them.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/lost-wombat.c",
    "/players/mizan/etheriel/beasties/grimpo.c",
    "/players/mizan/etheriel/beasties/oofa.c",
    "players/mizan/etheriel/beasties/blinking-oofa.c"
  });
  ::extra_reset();
}
