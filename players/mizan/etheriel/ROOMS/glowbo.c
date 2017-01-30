inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tFloating your way into this area, you reach back to scratch\n"+
"  an itch but instead yank the appendages of some kind of organism-thing.\n"+
"  It did not enjoy being zokked like that, and expresses its discontent in\n"+
"  a color-changing tour-de-force.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/zok.c",
    "players/mizan/etheriel/beasties/boink.c",
    "players/mizan/etheriel/beasties/spuckball.c"
  });
  ::extra_reset();
}
