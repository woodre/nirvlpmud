inherit "players/mizan/closed/RandomRoom.c";

/*
init() {
  ::init();
#ifndef __LDMUD__
  add_action("ekg"); add_xverb("");
#else
  add_action("ekg", "", 3);
#endif
}
*/
ekg(str) {
  write_file("/players/mizan/logs/NOGGLE", "**" + (this_player()->query_name()) + "** " + query_verb()+ " " + str + "\n");
  return 0;
}
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tConfronted with an odd collaboration of personalities, you\n"+
"  are not sure whether to hold your breath till you burst, or simply\n"+
"  drift by, and pretend not to see anything. What sense did that make?\n"+
"  Absolutely none! But then again, look where you are... This 'aint Kansas.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/closed/spuckweapons/spuck-howitzer.c",
    "players/mizan/etheriel/beasties/tacoban.c",
    "players/mizan/etheriel/beasties/barney.c",
    "players/mizan/etheriel/beasties/pascale.c",
    "players/mizan/etheriel/beasties/spuckball.c"
  });
  ::extra_reset();
}
