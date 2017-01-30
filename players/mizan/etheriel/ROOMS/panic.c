inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tBefore you is a large, looming, hulk of a thing whose size leaves\n"+
"  you in a steep bogglement. It does not appear to be hostile, but it\n"+
"  lumbers into a position such that you are at a disadvantage if you\n"+
"  try to escape its embrace.\n";
}

extra_reset() {
  object_names=({
  "players/mizan/etheriel/beasties/nogbeast.c",
  "players/mizan/etheriel/items/poohbear.c"
  });
  ::extra_reset();
}
