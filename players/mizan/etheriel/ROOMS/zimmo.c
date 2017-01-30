inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tEverything seems so quiet here. The spiralling backdrop of\n"+
"  the local 'area' seems to hold a tense, panicky mood. You get the\n"+
"  impression that fear drove everything away. You are left in a mildly\n"+
"  steep bogglement...\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/environs/exploder.c",
    "players/mizan/etheriel/beasties/beano.c"
  });
  ::extra_reset();
}
