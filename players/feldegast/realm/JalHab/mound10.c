#include "defs.h"

inherit MNDROOM;

void reset(int arg)
{
  int i;
  if(!arg)
  {
    short_desc=RED+"The Myrmidar Mound"+NORM;
    long_desc=
"  A wide ramp of rocks and packed clay descends into this cavern and\n\
then curves so that it is heading in the opposite direction.  A tunnel\n\
leads under the ramp through an archway, while two wide tunnels both\n\
lead north.\n";
    items=({
      "tunnels", "The passages are perhaps six feet high, circular, and well-travelled",
      "tunnel", "The passages are perhaps six feet high, circular, and well-travelled",        
      "ramp", "The ramp descends at a forty-five degree angle from north to\n"+
              "south and then curves back to the north where it meets the\n"+
              "rocky floor",
      "rocks", "Mostly chunks of sandstone and granite",
      "clay", "The clay is packed between the rocks",
      "cavern", "The cavern is about fifty feet square and thirty feet high",
      "archway", "The archway goes beneath the ramp",
    });
    dest_dir=({
      PATH+"mound11.c","northwest",
      PATH+"mound11.c","northeast",
      PATH+"mound15.c","east",
      PATH+"mound3.c","up",
    });
  }
  for(i=random(3)+1; i > 0; i--)
    move_object(clone_object(MON_PATH+(random(2)?"myrm-warrior":"myrm-worker")),this_object());
  if(!random(2)) move_object(clone_object(MON_PATH+"myrm-leader"),this_object());
}
