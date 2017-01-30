inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tA loud, thundering, droning noise almost scares you to death!\n"+
"  In vain you look around attempting to catch the culprit, and you scan\n"+
"  all four dimensions, but to no avail. Whatever caused that funky noise\n"+
"  got away with it entirely.\n";
}

query_zokko() { return "Zooooooom!"; }

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/bullfrog.c",
    "players/mizan/etheriel/beasties/lost-wombat.c",
    "players/mizan/etheriel/beasties/waterlemon.c",
    "players/mizan/etheriel/beasties/wub.c",
  });
  ::extra_reset();
  if(1==random(5)) {
move_object(clone_object("players/mizan/etheriel/heals/rawtoast.c"), this_object());
  move_object(clone_object("players/mizan/etheriel/heals/zokball.c"), this_object());
  }
}

