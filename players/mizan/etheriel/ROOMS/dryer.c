inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tTumbling and rolling about, you 'arrive' here in a slightly\n"+
"  confused and befoggled mental state. Having nothing to focus or regain\n"+
"  your bearings on, you can only ride and swirl helplessly with the strange\n"+
"  and inconsistent current.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/oomingmak.c",
    "players/mizan/etheriel/beasties/woogle.c",
    "players/mizan/etheriel/beasties/symidryl.c"
  });
  ::extra_reset();
}
