inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tYou hear a beautiful voice coming from somewhere, and being\n"+
"  more that slightly curious, you think your way towards it. The source\n"+
"  is a young maiden hovering near a blinking colormass, singing in a\n"+
"  tongue unfamiliar to you in front of an assortment of other 'creatures'.\n"+
"  The language she is singing in is irrelevant, since it brings some\n"+
"  sense of tranquility to your soul.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/Noika.c",
    "players/mizan/etheriel/beasties/silent-oofa.c",
    "players/mizan/etheriel/beasties/silent-beano.c",
    "players/mizan/etheriel/beasties/silent-spuckball.c",
    "players/mizan/etheriel/beasties/silent-beano.c"
  });
  ::extra_reset();
  if(1==random(1000)) {
  move_object(clone_object("players/mizan/etheriel/heals/dirtbag.c"), this_object());
  }
}
