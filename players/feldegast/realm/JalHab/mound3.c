#include "defs.h"

inherit MNDROOM;

void reset(int arg)
{
  int i;
  if(!arg) {
    short_desc=RED+"The Myrmidar Mound"+NORM;
    long_desc=
"  The tunnels are cool and humid, with a slightly sweet odor to them.\n\
The ceiling here rises to a good twenty feet and the walls have a\n\
radius of about thirty.  This appears to be some sort of central point\n\
or meeting place.  Tunnels leave in all directions, and a hole leads\n\
into the ground at a forty-five degree angle.\n";
    items=({
      "tunnels", "The passages are perhaps six feet high, circular, and well-travelled",  
      "ceiling", "It rises to a good twenty feet",
      "walls", "The cave is vaguely circular, with the walls about thirty\n"+
               "feet away from the center",
      "hole", "The hole is about six feet in diameter and leads deeper\n"+
              "into the earth",
    });
    dest_dir=({
      PATH+"mound2.c","north",
      PATH+"mound4.c","west",
      PATH+"mound5.c","southwest",
      PATH+"mound7.c","east",
      PATH+"mound10.c","down",
    });
  }
  for(i=random(3)+1; i > 0; i--)
    move_object(clone_object(MON_PATH+(random(2)?"myrm-warrior":"myrm-worker")),this_object());
  if(!random(2)) move_object(clone_object(MON_PATH+"myrm-leader"),this_object());
}
