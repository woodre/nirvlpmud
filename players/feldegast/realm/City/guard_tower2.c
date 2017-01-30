#include "defs.h"

inherit ROOM;

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="Ironheart Tower";
  long_desc=
"  This dimly lit room is the primary work and living area of the\n"+
"guards stationed at Ironheart tower.  A pipework stove in the corner\n"+
"radiates thin heat to the off-duty guards.  A nebulous clutter\n"+
"covers the long table in the center of the room, except for a tidy\n"+
"spot at the end where the sergeant of the watch works.\n";
  items=({
  });
  dest_dir=({
    PATH+"Haven/guard_tower3","up",
    PATH+"Haven/guard_tower1","down",
  });
}   
