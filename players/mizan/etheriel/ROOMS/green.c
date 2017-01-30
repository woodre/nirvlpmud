#include "/players/bastion/closed/color.h"
inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc=GREEN + "\tA pleasant, squishing noise can be heard coming from somewhere.\n"+
"  you decide that it must be some organism drifting nearby. To your\n"+
"  horror, you detect an local anomaly that is pulling  you towards it!\n"+
"  Panic-stricken and confused, you paddle and think deperately, but then\n"+
"  the familiar looming hulk of an Oofa drifts by, making that same noise.\n" + OFF;
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/oofa.c",
    "players/mizan/etheriel/beasties/spuckball.c",
    "players/mizan/etheriel/beasties/beano.c",
    "players/mizan/etheriel/beasties/boink.c",
    "players/mizan/etheriel/beasties/woogle.c"
  });
  ::extra_reset();
  if(1==random(1200)) {
  move_object(clone_object("players/mizan/etheriel/heals/portable_cow.c"), this_object());
  }
}
