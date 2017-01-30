inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tA funny thing happens here... as you close your eyes, you can\n"+
"  see the light and only then is the world around you exposed. This is\n"+
"  the only such 'visual' anomaly that you have encountered thus far.\n"+
"  One by one, the consistencies of the laws of nature fall. First gravity,\n"+
"  then motion, energy, and now visual light.\n";
}

extra_reset() {
  object_names=({
    "/players/mizan/etheriel/environs/chall-button.c",
    "players/mizan/etheriel/beasties/colormonger.c",
    "players/mizan/etheriel/beasties/ettin.c",
    "players/mizan/etheriel/beasties/spuckball.c"
  });
  ::extra_reset();
}
