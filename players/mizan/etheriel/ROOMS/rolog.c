inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tDrawn to a bright, brilliant light like a firefly, you\n"+
"  smile and gaze sheepishly at it until it suddenly fades and eventually\n"+
"  disappears. From deep within, you recognize the emerging shape as that\n"+
"  of a Snorri. You begin to ponder whether or not this is the mechanism\n"+
"  that spawns these oddly magnificent creatures...\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/environs/lampshade.c",
     "players/mizan/etheriel/beasties/colormonger3.c",
      "players/mizan/etheriel/beasties/spuckball.c",
    "players/mizan/etheriel/beasties/snorri.c",
    "players/mizan/etheriel/beasties/ziggle.c"
  });
  ::extra_reset();
  if(1==random(1000)) {
  move_object(clone_object("players/mizan/etheriel/heals/herring.c"), this_object());
  }
}
