inherit "players/mizan/closed/RandomRoom.c";

reset(arg) { ::reset(arg); if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tPelted by a fungling array of soft, squishy objects, only\n"+
"  after the barrage ends can you open your eyes. To your utter surprise\n"+
"  and bewilderment, a horde of Spuckballs greet you.. but something does\n"+
"  not feel right.\n";
}

extra_reset() {
  object_names=({
   "/players/mizan/etheriel/beasties/oofa.c",
   "/players/mizan/etheriel/beasties/oofa.c",
    "players/mizan/etheriel/beasties/mean-spuckball.c",
    "players/mizan/etheriel/beasties/mean-spuckball.c",
    "players/mizan/etheriel/beasties/mean-spuckball.c",
    "players/mizan/etheriel/beasties/mean-spuckball.c"
  });
  ::extra_reset();
  if(1==random(1000)) {
  move_object(clone_object("players/mizan/etheriel/heals/neutromuck.c"), this_object());
  }
}
