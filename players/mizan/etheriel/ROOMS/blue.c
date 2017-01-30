inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tThe one factor that has always been a constant in this wild\n"+
"  new place has been the factor of time. Now you realize that it was\n"+
"  truly an illusion, since you have absolutely no idea whether a few\n"+
"  minutes have passed since you entered this realm... or several hours?\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/spucktrooper.c",
    "players/mizan/etheriel/beasties/blinking-oofa.c",
    "players/mizan/etheriel/beasties/spuckball.c",
    "players/mizan/etheriel/beasties/spud.c",
    "players/mizan/etheriel/beasties/fuzzy.c",
    "players/mizan/etheriel/beasties/something.c"
  });
  ::extra_reset();
  if(1==random(1500)) {
  move_object(clone_object("players/mizan/etheriel/heals/portable_cow.c"), this_object());
  }
}
