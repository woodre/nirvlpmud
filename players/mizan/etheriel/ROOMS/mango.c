inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tThe turbulence of the ether-muck is very pronounced here, as you\n"+
"  actually feel a current that is pushing you... er... uhm... well...\n"+
"  Let's just say that it is pushing you in.. a direction. A vector. Yes!\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/hoojib.c",
    "players/mizan/etheriel/beasties/spuckball-b.c",
    "players/mizan/etheriel/beasties/blinking-oofa2.c",
    "players/mizan/etheriel/beasties/giraffe.c",
    "players/mizan/etheriel/environs/spigot.c"
  });
  ::extra_reset();
}
