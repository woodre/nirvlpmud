inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tThe current is very slow here, and actually somewhat predictable.\n"+
"  Trying to keep track of movement on three-sometimes-four dimensions is\n"+
"  harder than it seems. Therefore, the calm and tranquility present here\n"+
"  is relief for your confused and somewhat frayed mind.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/silent.c",
    "players/mizan/etheriel/beasties/spuckball.c",
    "players/mizan/etheriel/beasties/blinking-oofa2.c",
    "players/mizan/etheriel/environs/gleeclub-poster.c"
  });
  ::extra_reset();
  if(1==random(1600)) {
  move_object(clone_object("players/mizan/etheriel/heals/portable_cow.c"), this_object());
  }
}
