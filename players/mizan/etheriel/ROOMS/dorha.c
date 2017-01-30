inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\t'Enough of this bullshit!', you shout, and pretend that the\n"+
"  creatures (of questionable origins) are paying attention. Having enough\n"+
"  troubles moving around, you decide to fume and float in one spot.\n"+
"  Suddenly, a small, blinking globule of light passes in front of you and\n"+
"  without warning, explodes, apparently dying. You laugh uncontrollably.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/leonard.c",
    "players/mizan/etheriel/beasties/spuckball.c",
    "players/mizan/etheriel/beasties/cactus.c",
    "players/mizan/etheriel/beasties/tacoban.c"
  });
  ::extra_reset();
  if(1==random(500)) {
  move_object(clone_object("players/mizan/etheriel/heals/cheese.c"), this_object());
  }
}
