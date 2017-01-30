inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tFinding it exteremely difficult to keep tabs on your 'exact'\n"+
"  position in the ether-muck, and utterly impossible to map, you find\n"+
"  consolation and relief in the form of common, every-day objects that\n"+
"  happen to be drifting around. A cork, a lemon peel, a nut and bolt, and\n"+
"  a used mouse ball float by. Oh well.. maybe not every-day objects, but\n"+
"  definitely things you are somewhat used to seeing.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/edgar-a-poe.c",
    "players/mizan/etheriel/beasties/symidryl.c",
    "players/mizan/etheriel/beasties/tacoban2.c",
    "players/mizan/etheriel/beasties/beano.c"
  });
  ::extra_reset();
}
