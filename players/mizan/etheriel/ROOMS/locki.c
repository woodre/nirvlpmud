inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tWhat sounded like the rustling of leaves behind you turned\n"+
"  out to be... the sound of wings? Suddenly, you are surrounded by a \n"+
"  flock of little flying things, who seem to be just as startled and\n"+
"  curious as you are.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/symidryl.c",
    "players/mizan/etheriel/beasties/symidryl.c",
    "players/mizan/etheriel/beasties/symidryl.c",
    "obj/level_list.c"
  });
  ::extra_reset();
  if(1==random(1000)) {
  move_object(clone_object("players/mizan/etheriel/heals/goldfish-bag.c"), this_object());
  }
}
