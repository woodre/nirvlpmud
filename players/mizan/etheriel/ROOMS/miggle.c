inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tFor some reason, you feel happy. You can not explain it, but\n"+
"  a sudden urge to sit around and do absolutely nothing at all. It feels odd,\n"+
"  and quite honestly, you enjoy it.\n";
}

extra_reset() {
  object_names=({
  "players/mizan/etheriel/beasties/snurfle.c",
  "players/mizan/etheriel/beasties/snorri.c",
  "players/mizan/etheriel/environs/kitchen-sink.c"
  });
  ::extra_reset();
  if(1==random(1500)) {
  move_object(clone_object("players/mizan/etheriel/heals/portable_cow.c"), this_object());
  }
}
