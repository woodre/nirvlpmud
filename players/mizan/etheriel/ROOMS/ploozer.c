inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\t'Arriving' here you feel dizzy. Real dizzy. Ouch. Something just\n"+
"  poked you in the ribs. You blink, and peer intently around. Something is\n"+
"  in the room with you.\n";
}

extra_reset() {
  object_names=({
  "players/mizan/etheriel/beasties/oofa.c",
  "players/mizan/etheriel/beasties/oofa.c",
  "players/mizan/etheriel/beasties/waterlemon2.c",
  "players/mizan/etheriel/beasties/silent.c",
  "players/mizan/etheriel/beasties/ettin.c"
  });
  ::extra_reset();
}
