inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tAlthough the environment around you is inherently unstable and\n"+
"  utterly unpredictable, you welcome its embrace- it is a fresh departure\n"+
"  of the 'normal' world you are accustomed to. You are not sure if the\n"+
"  'creatures' living here know that they are blessed with such an\n"+
"  interesting gift, but whether they care or not is the real issue.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/colormonger.c",
    "players/mizan/etheriel/beasties/ziggle.c",
    "players/mizan/etheriel/environs/expwy-sign.c"
  });
  ::extra_reset();
}
