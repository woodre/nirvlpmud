inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tA powerful and familiar odor assaults your sense of smell.\n"+
"  Best described as Fulton Fish market in downtown New York City, it is\n"+
"  both unpleasant, and yet, soothing in its familiarity. Either way, it\n"+
"  is strong enough to keep your attention from the beasties that share\n"+
"  this space in the 'ether-muck' with you.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/tunafish.c",
    "players/mizan/etheriel/beasties/flytrap.c",
    "players/mizan/etheriel/items/can-opener.c",
    "players/mizan/etheriel/beasties/tunafish.c"
  });
  ::extra_reset();
  if(1==random(400)) {
  move_object(clone_object("players/mizan/etheriel/heals/portable_cow.c"), this_object());
  }
}
