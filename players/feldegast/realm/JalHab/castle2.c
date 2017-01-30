#include "defs.h"

inherit ROOM;

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc=BOLD+BLK+"Castle Magnarn"+NORM;
  long_desc=
"  This was once the castle's great hall.  A great sandstone staircase\n\
leads to the upper level.  The archway to the east has collapsed,\n\
but the archway to the kitchen remains sound.\n";
  items=({
    "staircase","The staircase appears to have stood the test of time quite well",
    "archway", "The archway to the east has been flooded with rubble.\n"+
               "There is no way through",
    "archway", "You cannot see it very well from here",
  });
  dest_dir=({
    PATH+"castle3.c","west",
    PATH+"castle1.c","south",
    PATH+"castle4.c","up",
  });
}
