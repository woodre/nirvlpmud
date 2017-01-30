inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tThe colors seem a bit more sedated here for some reason...\n"+
"  Something rather uncommonly expressed in this realm begins to\n"+
"  emerge. You feel somewhat sad... depressed even.. but that feeling\n"+
"  seems to be caused by something external.. like the dark blue vortex\n"+
"  swirling before you...\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/silent-beano.c",
    "players/mizan/etheriel/beasties/silent-beano.c"
  });
  ::extra_reset();
  if(1==random(1000)) {
  move_object(clone_object("players/mizan/etheriel/heals/portable_cow.c"), this_object());
  }
}
