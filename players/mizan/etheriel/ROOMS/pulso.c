inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tDesperately trying to get a closer look at the image of this\n"+
"  beautiful figure that hovers before you, it suddenly fades, to reveal a\n"+
"  horribly grotesque and misbegotten figure. Coming closer to it, you\n"+
"  begin to detect a foul, rancid odor of undead origins.\n"; 
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/betelgeuse.c",
    "players/mizan/etheriel/beasties/spuckball.c",
    "players/mizan/etheriel/beasties/light-bulb.c"
  });
  ::extra_reset();
}
