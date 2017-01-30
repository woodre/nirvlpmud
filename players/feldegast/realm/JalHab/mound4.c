#include "defs.h"

inherit MNDROOM;

void reset(int arg)
{
  if(!arg) {
    short_desc=RED+"The Myrmidar Mound"+NORM;
    long_desc=
"  The tunnels are cool and humid, with a slightly sweet odor to them.\n\
The tunnel ends abrubtly here in a natural pocket, as though whoever\n\
had been digging it had simply decided that this was a good place to\n\
stop.\n";
    items=({
      "tunnels", "The passages are perhaps six feet high, circular, and well-travelled",  
    });
    dest_dir=({
      PATH+"mound3.c","east",
    });
  }
  if(!present("myrmidar") && !random(2))
    move_object(clone_object(MON_PATH+"myrm-worker"),this_object());
}
