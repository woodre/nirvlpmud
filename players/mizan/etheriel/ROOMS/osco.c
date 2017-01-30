inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tOne more minute of this mindless folly would do a world of hurt\n"+
"  to the average person, but you are actually beginning to enjoy moving\n"+
"  around in this 'place'. It seems that the environment has a direct role\n"+
"  in stimulating your mood. You deduce that the more colorful and vivid\n"+
"  a part of this realm is, the happier you are. The more complexity, and\n"+
"  the more paranoid you feel. Right 'here' it's sedated, but not dead.\n"+
"  Likewise, you feel introspective and relaxed.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/oomingmak.c",
    "players/mizan/etheriel/beasties/boink.c",
    "players/mizan/etheriel/beasties/psychotic-barney.c",
    "players/mizan/etheriel/beasties/spuckball.c"
  });
  ::extra_reset();
/*
  if(1==random(4)) {
  move_object(clone_object("players/mizan/etheriel/beasties/spucktrooper.c"), this_object());
  }
 */
}
