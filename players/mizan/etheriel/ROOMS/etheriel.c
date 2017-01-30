inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tA bright source of light somewhere nearby causes you to squint\n"+
"  painfully at first, but you grow accustomed to it rather quickly. Almost\n"+
"  solar in nature, it feels soothing and you can't resist the temptation\n"+
"  to bask in its rays. Suddenly, you hear voices, a chorus of captivatingly\n"+
"  beautiful sounds coming from very closeby, you can barely see the silouhette\n"+
"  of a slim, golden haired figure in the light.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/Etheriel.c",
    "players/mizan/etheriel/beasties/spuckball.c",
    "players/mizan/etheriel/beasties/spuckball.c",
    "players/mizan/etheriel/beasties/beano.c",
    "players/mizan/etheriel/beasties/oofa.c"
  });
  ::extra_reset();
  if(1==random(670)) {
  move_object(clone_object("players/mizan/etheriel/heals/spam.c"), this_object());
  }
}
