#include "defs.h"

inherit MNDROOM;

void reset(int arg)
{
  int i;
  if(!arg)
  {
    short_desc=RED+"The Myrmidar Mound"+NORM;
    long_desc=
"  A large stalactite hangs down from the ceiling of this natural cave,\n\
which seems to serve as a junction for three large tunnels.  A rancid\n\
stench seems to come from the west.\n";
    items=({
      "stalactite", "The calcified rock hangs down from the ceiling",
      "tunnels", "You see three of them leading off in different directions",
      "junction", "Three tunnels meet here",
    });
    dest_dir=({
      PATH+"mound13.c","west",
      PATH+"mound17.c","east",
      PATH+"mound11.c","south",
    });
  }
  if(!present("myrmidar"))
    for(i=random(3); i > 0; i--)
      move_object(clone_object(MON_PATH+((random(2))?"myrm-warrior":"myrm-worker")),this_object());
}
