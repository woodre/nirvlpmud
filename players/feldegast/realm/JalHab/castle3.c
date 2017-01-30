#include "defs.h"

inherit ROOM;

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc=BOLD+BLK+"Castle Magnarn"+NORM;
  long_desc=
"  At one time this might've been a kitchen.  The room is lined with\n\
cabinets and a large fireplace is on the northern wall.  A cutting\n\
table sits in the middle of the room.  A staircase spirals down into\n\
the cellar.\n";
  items=({
    "kitchen", "Yes, a kitchen",
    "cabinets", "The wooden cabinets are slowly deteriorating",
    "fireplace", "It is large enough to roast a pig",
    "table", "You can make out the knifemarks where someone once cut here",
    "staircase", "A creaky metal staircase that spirals down",
    "cellar", "It is too dark",
  });
  dest_dir=({
    PATH+"castle2.c","east",
    PATH+"castle8.c","down",
  });
}
