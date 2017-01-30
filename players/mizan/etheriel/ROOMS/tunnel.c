inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tA cracking 'pop' is heard coming from nearby. Something that \n"+
"  resembled a Spuckball that was drifting abreast of you suddenly just\n"+
"  vanished without a trace. The only evidence of its departure is the\n"+
"  subtle vacuum left by its disappearance from the world.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/blinking-grimpo.c",
    "players/mizan/etheriel/beasties/woogle.c",
    "players/mizan/etheriel/beasties/fuzzle.c"
  });
  ::extra_reset();
}
