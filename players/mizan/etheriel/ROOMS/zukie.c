inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tFor some reason, you feel happy. You can not explain it, but\n"+
"  a sudden urge to float about and do absolutely nothing washes over you\n"+
"  and quite honestly, you enjoy it. But isnt that what you're doing\n"+
"  right now?\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/giraffe.c",
    "players/mizan/etheriel/beasties/spuckball.c",
    "players/mizan/etheriel/beasties/spuckball.c",
    "players/mizan/etheriel/beasties/beano.c"
  });
  ::extra_reset();
  if(1==random(10)) {
  move_object(clone_object("players/mizan/etheriel/beasties/cactus.c"), this_object());
  }
}
