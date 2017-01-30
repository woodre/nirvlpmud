inherit "players/mizan/closed/RandomRoom.c";
#include "/players/bastion/closed/color.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc=GREEN + "\tFor some reason, you have the desire to eat pickles.\n"+
"  Even the squishy pickles served at run-down corner delicatessen\n"+
"  will do. No, the urge has nothing to do with the fact that a strange\n"+
"  beast shaped like a pickle hovers before you. I would think not.\n" + OFF;
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/environs/stop-sign.c",
    "players/mizan/etheriel/beasties/woogle.c",
    "players/mizan/etheriel/beasties/something.c",
    "players/mizan/etheriel/beasties/normal-beast.c"
  });
  ::extra_reset();
}
