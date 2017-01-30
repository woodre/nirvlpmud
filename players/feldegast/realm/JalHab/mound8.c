#include "defs.h"

inherit MNDROOM;

void reset(int arg)
{
  if(!arg) {
    short_desc=RED+"The Myrmidar Mound"+NORM;
    long_desc=
"  The tunnels are cool and humid, with a slightly sweet odor to\n\
them.  The passage widens here and is divided by a series of pillars\n\
constructed of bits and pieces of sandstone haphazardly piled atop\n\
each other.\n";
    items=({
      "tunnels", "The passages are perhaps six feet high, circular, and well-travelled",        
      "pillars", "The pillars, constructed out of chunks of sandstone, are\n"+
                 "supporting the ceiling",
      "sandstone", "The chunks of sandstone appear to've been salvaged from\n"+
                   "other sections of the mound",
    });
    dest_dir=({
      PATH+"mound7.c","northwest",
      PATH+"mound9","southwest",
    });
  }
  if(!present("myrmidar") && random(2))
    move_object(clone_object(MON_PATH+"myrm-worker.c"),this_object());
}
