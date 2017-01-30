#include "/players/catacomb/misc/ansi.h"
#define TP this_player()

inherit "room/room";

reset(arg) 
{
  if(arg) return;
  set_light(1);

  short_desc ="Second level of the Durkor Caverns" ;
  long_desc =(
  "  The decaying old bridge sways dangerously over the river of lava\n"+
  "below.  Each step seems to bring about another outburst of flame \n"+
  "from the river below.  The fires run rampant about the bridge, but\n"+
  "it somehow avoids being destroyed.\n"); 

  items = ({
    "bridge",
    "The bridge seems to sway away from each flame that tries to consume it",
    "river",
    "The river of lava flows beneath the bridge with flames errupting regularly", 
    "lava",
    "The river of lava flows beneath the bridge with flames errupting regularly", 
    "flame",
    "The flames errupt in front of you",
    "flames",
    "The flames errupt in front of you",
  });

  dest_dir = ({
    "/players/catacomb/Cavern/rooms/lvl2_5.c","north",
    "/players/catacomb/Cavern/rooms/lvl2_13.c","south"
  });

if(!present("elemental"))
{
   move_object(clone_object("/players/catacomb/Cavern/mobs/FElem2.c"),
    this_object());
   move_object(clone_object("/players/catacomb/Cavern/mobs/FElem1.c"),
    this_object());
}
}
