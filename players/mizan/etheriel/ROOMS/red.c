#include "/players/boltar/things/esc.h"
#define Blink esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40mblink"+esc+"[0m"
inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tYou are not too sure what extended exposure to a completely\n"+
"  unresearched, kaliedoscopic environment can do to your eyesight.\n"+
"  Never mind that, but what about its effects on the brain? Until you\n"+
"  start seeing double double, or text starts to "+Blink+" then don't\n"+
"  worry about a thing. Just catch the current and lime out...\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/blinking-oofa.c",
    "players/mizan/etheriel/items/nitro-glycerin.c",
    "players/mizan/etheriel/beasties/snorri.c",
    "players/mizan/etheriel/environs/chall-button.c",
    "players/mizan/etheriel/items/bucket.c"
  });
  ::extra_reset();
  if(1==random(1000)) {
  move_object(clone_object("players/mizan/etheriel/heals/portable_cow.c"), this_object());
  }
}

init()
{
/*
  heh.  commented out 6.18.01 by verte

  add_action("bl","bl");
*/
  ::init();
}

bl()
{
   call_other("/players/mizan/etheriel/items/mavira.c","???");
  return 1;
}
