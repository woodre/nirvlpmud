#include "/players/bastion/closed/color.h"
inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc=RED +"\tIt seems slightly more colourful here, as you feel that you are\n"+
"  close to some kind of center of mass. Many small organism-type-things,\n"+
"  which appear to be simply colored bubbles, swarm around you and dart\n"+
"  by. They seem to be intelligent, and observe you quietly and curiously.\n" + OFF;
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/grimpo.c",
    "players/mizan/etheriel/beasties/oofa.c"
  });
  ::extra_reset();
}
