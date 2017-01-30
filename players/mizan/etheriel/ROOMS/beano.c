inherit "players/mizan/closed/RandomRoom.c";

reset(arg) { ::reset(arg); if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tAn array of ever-shapeshifting forms greets you when you\n"+
"  think yourself into this area. Changing colors just as fast as they\n"+
"  change shape, they appear to be 'dancing'. You can't help\n"+
"  but watch for a little while longer... before you start killing them!\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/beano.c",
    "players/mizan/etheriel/beasties/beano.c",
    "players/mizan/etheriel/beasties/beano.c",
    "players/mizan/etheriel/beasties/beano.c"
  });
  ::extra_reset();
   if(1==random(1200)) {
   move_object(clone_object("players/mizan/etheriel/heals/portable_cow.c"), this_object());
  }
}
