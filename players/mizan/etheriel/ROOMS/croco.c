inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tGloop. Bloooop. Glop. Sound takes on a whole new meaning here,\n"+
"  as your voice distorts into an organic mush when you try to speak\n"+
"  here. Try it! You try to form proper sentences but the words seem to\n"+
"  slurble and glof with every attempt.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/environs/slur-device.c",
    "players/mizan/etheriel/beasties/spucktrooper.c",
    "players/mizan/etheriel/beasties/beano.c"
  });
  ::extra_reset();
}
