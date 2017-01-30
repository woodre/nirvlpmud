inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tAs you pass by this area, something very small and of\n"+
"  constantly changing color drifts through your stomach. It emerges,\n"+
"  covered in what you recognize as your lunch. Gross.\n";
}

extra_reset() {
  object_names=({
  "players/mizan/etheriel/beasties/spuckball.c",
  "players/mizan/etheriel/beasties/mog.c",
  "players/mizan/etheriel/beasties/yerkle-tree.c",
  "players/mizan/etheriel/beasties/lost-wombat.c"
  });
  ::extra_reset();
}
