inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tFor some reason, the current here is slow and thick, and you\n"+
"  feel stagnant and sluggish. The colors of the ether-muck here are a bit\n"+
"  drab and sedated, even stale, if you want to put it that way.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/environs/tiamat-prison.c",
    "players/mizan/etheriel/beasties/blinking-oofa2.c",
    "players/mizan/etheriel/beasties/boofer.c"
  });
  ::extra_reset();
}
