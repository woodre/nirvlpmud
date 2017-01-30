#include "defs.h"

inherit ROOM;

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc=BOLD+BLK+"Castle Magnarn"+NORM;
  long_desc=
"  A stained glass window at the top of the stairs has miraculously\n\
survived the decay which has afflicted the rest of this castle.  In\n\
the dim light that streams through the window you make out three\n\
stone archways leading in different directions.\n";
  items=({
    "window",
      "The scene in the window depicts a robed man bearing a staff\n"+
      "summoning forth a horde of demons to do his bidding",
    "stairs",
      "The stairs descend down to the first floor",
    "archways",
      "The archway to the west appears to have been cleared of rubble\n"+
      "recently.  The archway to the north leads into a chapel, and\n"+
      "you feel a breeze coming from the archway to the east",
  });
  dest_dir=({
    PATH+"castle6.c","north",
    PATH+"castle5.c","west",
    PATH+"castle7.c","east",
    PATH+"castle2.c","down",
  });
}
