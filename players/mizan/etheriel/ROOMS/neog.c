inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tOne thing you notice is that this realm and golf have a lot \n"+
"  in common. Yes, golf, that sport that most people refer to as 'Men in\n"+
"  ugly pants walking on grass'. The truth is that golf brings out the best\n"+
"  and the worst in people. It requien mind, and a good\n"+
"  deal of trial and error. You are beginning to realize the same about\n"+
"  this realm.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/sarawak.c",
    "players/mizan/etheriel/beasties/fuzzle.c",
    "players/mizan/etheriel/beasties/spuckball.c"
  });
  ::extra_reset();
  if(1==random(1000)) {
  move_object(clone_object("players/mizan/etheriel/heals/half-note.c"), this_object());
  }
}
