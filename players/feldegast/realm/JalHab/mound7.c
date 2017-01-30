#include "defs.h"

inherit MNDROOM;

void reset(int arg)
{
  if(!arg) {
    short_desc=RED+"The Myrmidar Mound"+NORM;
    long_desc=
"  A tumble of rocks have fallen on the ground here at an\n\
intersection of three passages.  You feel a slight breeze\n\
coming from the northwest.\n";
    items=({
      "passages", "The passages are perhaps six feet high, circular, and well-travelled",  
      "rocks", "The rocks come from a section of the ceiling and wall that\n"+
               "have collapsed.  This section of the tunnels doesn't seem\n"+
               "to be very stable",
      "breeze", "You try catching the breeze by surprise, but you just can't\n"+
                "quite see it",
    });
    dest_dir=({
      PATH+"mound6.c","northwest",
      PATH+"mound3.c","west",
      PATH+"mound8.c","southeast",
    });
  }
  if(!present("myrmidar") && random(2))
    move_object(clone_object(MON_PATH+"myrm-worker.c"),this_object());
}
