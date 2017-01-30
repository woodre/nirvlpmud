inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\t'A stranger in a strange land.' That's what you feel like.\n"+
"  You feel strange inside too. Semi-trapped in a whimsical world of ever-\n"+
"  changing colors and environments, you decide to make the most of it.\n"+
"  So.. at the top of your lungs, you scream 'Garbanzo!!!'\n"+
"  All of the creatures nearby float and drift about, and you remain\n"+
"  un-noticed. Well, at least you tried...\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/blinking-oofa.c",
    "players/mizan/etheriel/beasties/snorri.c",
    "players/mizan/etheriel/beasties/tacoban.c"
  });
  ::extra_reset();
  if(1==random(3)) {
  move_object(clone_object("players/mizan/etheriel/beasties/woogle.c"), this_object());
  }
}
