inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tA strange sensation courses its way about your body...\n"+
"  You feel as if a hundred million tiny critters crawled into your \n"+
"  clothing and began dancing on your skin. It is not an unpleasant feeling,\n"+
"  by any means, but deep down, you wonder about its origins. However, if\n"+
"  you questioned everything that went on around here, your brain would\n"+
"  quite possibly explode.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/flytrap.c",
    "players/mizan/etheriel/beasties/snorri.c",
    "players/mizan/etheriel/beasties/mboofer.c"
  });
  ::extra_reset();
  if(1==random(1000)) {
  move_object(clone_object("players/mizan/etheriel/heals/herring.c"), this_object());
  }
}
