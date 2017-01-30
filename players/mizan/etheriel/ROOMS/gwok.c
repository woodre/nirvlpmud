inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tTurning around to scratch yourself, you are greeted by a\n"+
"  low-pressure shockwave that pounds against you with the subtlety of a\n"+
"  bull in a china shop. Gathering your senses, you could have sworn that\n"+
"  you saw a gaping rift in the fabric of the realm, but in a split second\n"+
"  flash it closes up again.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/waldo.c",
    "players/mizan/etheriel/beasties/spucktrooper.c",
    "players/mizan/etheriel/beasties/woogle.c",
    "players/mizan/etheriel/beasties/spuckball.c"
  });
  ::extra_reset();
  if(1==random(1000)) {
  move_object(clone_object("players/mizan/etheriel/heals/half-note.c"), this_object());
  }
}
