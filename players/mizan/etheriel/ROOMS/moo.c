inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tSomething rather odd and inconsistent with what you have\n"+
"  seen in this freak dimension thus far grabs your attention. A solitary\n"+
"  chunk of earth drifts by, completely overgrown with grass. There\n"+
"  appears to be something standing in it, nibbling at the grass happily.\n";
}

extra_reset() {
  object_names=({
  "players/mizan/etheriel/beasties/blinking-oofa.c",
  "players/mizan/etheriel/environs/lampshade.c"
  });
  call_other("/players/mizan/etheriel/beasties/moo.c", "???");
  ::extra_reset();
}
