inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tA soft, fuzzy ball of light suddenly slams into your belly\n"+
"  and ricochets into the unknown. A short while later, you hear a\n"+
"  thundering explosion, and within seconds are caught up in a spectacular\n"+
"  array of millions of those identical fuzzy-light balls, rushing past\n"+
"  you at an extraordinary speed.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/flynn.c",
    "players/mizan/etheriel/beasties/symidryl.c",
    "players/mizan/etheriel/beasties/something.c"
  });
  ::extra_reset();
}
