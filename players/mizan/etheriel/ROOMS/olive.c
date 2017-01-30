inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="	In the distance you can see two organism-type things locked in\n"+
"  mortal combat. You've never seen these things (which look like Oofas)\n"+
"  ever fight each other. It is a strange, exotic ballet of sorts, in which\n"+
"  one tries to overcome the other by engulfing it.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/keroleen.c",
    "players/mizan/etheriel/beasties/tacoban.c",
    "players/mizan/etheriel/beasties/tacoban.c",
    "players/mizan/etheriel/environs/faucet.c"
  });
  ::extra_reset();
}
