inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tSwirling into this area at a breakneck pace, you are slowed\n"+
"  down only by the hulking mass of an Oofa, which only serves as an\n"+
"  aerobrake that slows you down just enough to keep you from getting\n"+
"  impaled by what you recognize as a street sign. Crashing into it, you\n"+
"  are effectively stopped but your head begins to ring. Pleasant.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/environs/wz-pinball.c",
    "players/mizan/etheriel/environs/roadsign.c",
    "players/mizan/etheriel/beasties/blinking-boofer.c",
    "players/mizan/etheriel/beasties/silent-oofa.c"
  });
  ::extra_reset();
}
