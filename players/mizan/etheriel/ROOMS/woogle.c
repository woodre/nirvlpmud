inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  short_desc="Plane of Etheriel";
  set_light(1);
  long_desc="\tFor a moment, you feel slightly nauseated by the lack of\n"+
"  gravity, and any of the normal laws of nature, for that matter. The\n"+
"  place you are floating in is deceptively large, because of the amount\n"+
"  of time you have wasted trying to get your bearings.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/mr-lemonguy.c",
    "players/mizan/etheriel/beasties/tacoban.c",
  "players/mizan/etheriel/beasties/spuckball.c",
  "players/mizan/etheriel/beasties/spud.c",
  "players/mizan/etheriel/beasties/beano.c",
  "players/mizan/etheriel/beasties/ettin.c"
  });
  ::extra_reset();
}
