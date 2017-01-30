inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tSomehow, everything seems a bit more ordered around here.\n"+
"  Not quite sure how to interpret it, you are not used to the patterns\n"+
"  in this environment having order, and even a 'stripey' appearance. \n"+
"  Things usually have a color pattern much like Auguste Renoir, painting\n"+
"  style, but with infinite suggestions of shapes and figures in the\n"+
"  ever-changing ether-muck.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/environs/shirt-dispenser.c",
    "players/mizan/etheriel/beasties/woogle.c",
    "players/mizan/etheriel/beasties/silent-boofer.c"
  });
  ::extra_reset();
}
