inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tSuddenly, the ether-muck around you seems to burst into\n"+
"  motion... Ever-changing colors increase in frequency, and the 'backlight'\n"+
"  that exists throughout the realm (one of the few consistencies.. almost)\n"+
"  seems to get brighter exponentially. You feel... Happy. Looking around,\n"+
"  you don't see any Snorris floating about. Hmm. There must be another\n"+
"  reason then.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/morkle.c",
    "players/mizan/etheriel/beasties/otterley.c",
    "players/mizan/etheriel/beasties/lost-wombat.c"
  });
  ::extra_reset();
}
