inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tA sudden and brief return of some kind of localized gravity\n"+
"  catches you off guard, and you collide into an oil drum, but just as\n"+
"  fast as it held on, it loses grip and you are left again to drift in\n"+
"  the funky strange environment known as the ether-muck.\n";
}

query_zokko() { return "Zooooooom!"; }

extra_reset() {
  object_names=({
    "players/mizan/etheriel/items/portable-panic-btn.c",
    "players/mizan/etheriel/beasties/waterlemon.c",
    "players/mizan/etheriel/beasties/tacoban.c",
    "players/mizan/etheriel/beasties/symidryl.c",
  });
  ::extra_reset();
  if(1==random(5)) {
  move_object(clone_object("players/mizan/etheriel/heals/zokball.c"), this_object());
  }
}
