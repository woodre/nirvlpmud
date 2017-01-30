inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tYou blink. The colors here are much brighter than most places,\n"+
"  and ever-changing. An ultra-vivid burst of something flashes near your\n"+
"  head, and you feel whatever it is phase right through your body. It\n"+
"  actually feels pleasant, a tingling, unfamiliar feeling as another\n"+
"  organism shares its thoughts with you, and likewise...\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/heals/banana.c",
    "players/mizan/etheriel/beasties/spuckball.c",
    "players/mizan/etheriel/beasties/snurfle.c",
    "players/mizan/etheriel/beasties/ziggle.c"
  });
  ::extra_reset();
  if(1==random(200)) {
  move_object(clone_object("players/mizan/etheriel/items/squishweapon.c"), this_object());
  }
}
