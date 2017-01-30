inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tDrifting at its own lesiurely pace is quite possibly the\n"+
"  largest blob of stuff here, aside from Spuck. Lumbering along at a\n"+
"  slow clip, its massive form continually adjusts in shape and color,\n"+
"  and it is completely oblivious to your presence.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/nogbeast.c",
    "players/mizan/etheriel/beasties/spuckball-b",
    "players/mizan/etheriel/beasties/hoojib.c"
  });
  ::extra_reset();
  if(1==random(100)) {
  move_object(clone_object("players/mizan/etheriel/items/ac-guitar.c"), this_object());
  }
}
