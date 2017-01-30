inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tSuddenly, your mind goes blank, and the only thing you can\n"+
"  think about is the sound of small bells jingling, and the gentle\n"+
"  flowing noise water makes when it gushes out of a garden hose.\n"+
"  Wow. Truly intense. You stop and wonder if there was anything that\n"+
"  you may have inhaled, ingested, etc. from the ether-muck that could\n"+
"  have caused such silly thoughts...\n";
}

query_zokko() { return "Zooooooom!"; }

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/lawnmower.c",
    "players/mizan/etheriel/beasties/waterlemon.c",
    "players/mizan/etheriel/beasties/mboofer.c",
    "players/mizan/etheriel/beasties/cactus.c",
  });
  ::extra_reset();
  if(1==random(2)) {
  move_object(clone_object("players/mizan/etheriel/heals/rawtoast.c"), this_object());
  }
}

