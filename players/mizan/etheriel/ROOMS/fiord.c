inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tConverging on a large, orange blob of goo is a flock of.. birds?\n"+
"  No, they're not planes either, and definitely not men in tights with\n"+
"  capes on.. but they do resemble dragons. The chirping sounds are really\n"+
"  beginning to make you homicidal!\n";
}

extra_reset() { 
  object_names=({
    "players/mizan/etheriel/items/nitro-glycerin.c",
    "players/mizan/etheriel/beasties/mboofer.c",
    "players/mizan/etheriel/beasties/beano.c",
    "players/mizan/etheriel/beasties/symidryl.c",
    "players/mizan/etheriel/beasties/symidryl.c",
    "players/mizan/etheriel/beasties/symidryl.c"
  });
  ::extra_reset();
  if(1==random(50)) {
  move_object(clone_object("obj/level_list.c"), this_object());
  }
}
