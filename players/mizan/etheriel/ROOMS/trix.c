inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tA large sign pops out of nowhere, barely colliding with you\n"+
"  but at the last possible moment you veer away and escape certain injury.\n"+
"  Its things like these that make travelling here somewhat hazardous, as\n"+
"  a few moments ago you barely escaped an encounter with a bowling ball.\n"+
"  however, something about this sign catches your eye...\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/environs/undead-sign.c",
    "players/mizan/etheriel/beasties/tacoban.c",
    "players/mizan/etheriel/beasties/bleh.c",
    "players/mizan/etheriel/beasties/fuzzy.c"
  });
  ::extra_reset();
}
