inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tSuddenly, a pleasant memory from long ago resurfaces in you mind\n"+
"  and you spend an unspecified amount of time reminiscing in it. Whether\n"+
"  or not it was a dream, a thought, something you once saw, you are\n"+
"  unsure, but it was something from your early childhood, and you remember\n"+
"  seeing the 'landscape' from this place in it.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/environs/seefeel.c",
    "players/mizan/etheriel/beasties/pogo.c",
    "players/mizan/etheriel/beasties/moogle.c",
    "players/mizan/etheriel/beasties/fuzzle.c"
  });
  ::extra_reset();
  if(1==random(1000)) {
  move_object(clone_object("players/mizan/etheriel/heals/herring.c"), this_object());
  }
}
