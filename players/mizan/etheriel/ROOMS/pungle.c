inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tNever before has any place you have visited been so strikingly\n"+
"  beautiful and yet ugly at the same time. So lawless and carefree,\n"+
"  yet so ordered and precise. So chaotic and random, yet knowingly predictable.\n"+
"  So strange and exotic, yet familiar deep down like you've known this\n"+
"  place from once upon a dream...\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/environs/to-amelia.c",
    "players/mizan/etheriel/beasties/giraffe.c",
    "players/mizan/etheriel/beasties/woogle.c"
  });
  ::extra_reset();
  if(1==random(1000)) {
  move_object(clone_object("players/mizan/etheriel/heals/orange.c"), this_object());
  }
}
