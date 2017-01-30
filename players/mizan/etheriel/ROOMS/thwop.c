inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tBless your creators for the gift of the 'sixth' sense.\n"+
"  Previously one who doubted it, you have come to rely heavily on its use\n"+
"  traversing this realm. Your confidence in yourself soars, upon the\n"+
"  discovery of an ability that you never thought you had, and the quick\n"+
"  mastery of its use when you found it.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/environs/spuggle-machine.c",
    "players/mizan/etheriel/beasties/uckier.c",
    "players/mizan/etheriel/beasties/spuckball.c"
  });
  ::extra_reset();
  if(1==random(1000)) {
  move_object(clone_object("players/mizan/etheriel/heals/bunupills.c"), this_object());
  }
}
