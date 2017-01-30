#include "/players/fakir/color.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("eaglet");
set_alias("chick");
set_race("creature");
set_short("An Eaglet");
set_long(
  "Covered in feathers but for its naked head, it is not yet ready to\n"+
  "leave the nest.  Its talons are not yet strong enough to capture or\n"+
  "kill, and the wing feathers still need to grow a bit.  Its beak is\n"+
  "well developed and strong however.  It will become a fine predator\n"+
  "in time.\n");

set_level(4);
set_hp(30 +random (20));
set_al(0);
set_wc(4 + random (2));
set_ac(2 + random (2));
set_aggressive(0);

}


