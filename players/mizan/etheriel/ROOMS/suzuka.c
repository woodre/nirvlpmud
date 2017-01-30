inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tIf this is what death is like, you have come to the conclusion\n"+
"  that you would not like to die. Being that movement takes on a whole\n"+
"  new meaning here, the ability to phase through certain things is a mixed\n"+
"  blessing. The reaction of some of the 'creatures' here can be related\n"+
"  to that of a human being seeing a misty apparation of origins unknown\n"+
"  before them. Natural reaction? Run and scream. That's not a swell way to\n"+
"  make new friends.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/environs/lamppost.c",
    "players/mizan/etheriel/beasties/spuckball.c",
    "players/ulath/crap/sofa.c",
    "players/mizan/etheriel/beasties/beano.c",
    "players/mizan/etheriel/beasties/spud.c",
    "players/mizan/etheriel/beasties/nogbeast.c"
  });
  ::extra_reset();
  if(1==random(450)) {
  move_object(clone_object("players/mizan/etheriel/heals/portable_cow.c"), this_object());
  }
}
