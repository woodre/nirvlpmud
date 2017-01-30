#include "/players/catacomb/misc/ansi.h"

inherit "room/room";

reset(arg) 
{
  if(arg) return;
  set_light(1);

  short_desc ="Second level of the Durkor Caverns" ;
  long_desc =(
  "  A fork in the passageway forces a decision.  To the east it \n"+
  "becomes much warmer and thhe glow of flames can be seen. The\n"+
  "southern path is its complete opposite.  The air is much cooler \n"+
  "and very dark.  The rocks to the south seem to be placed \n"+
  "strategically for an ambush.\n"); 

  items = ({
    "passage",
    "The passage splits of to the south and east", 
    "glow",
    "The glow from the east comes from the many flames", 
    "flames",
    "The flames jump up out of something to the east giving the cavern an orange glow",
    "flame",
    "The flames to the east give the tunnel an eerie orange glow",
    "rocks",
    "The rocks seem to be placed strategically for an ambush"
  });

  dest_dir = ({
    "/players/catacomb/Cavern/rooms/lvl2_3.c","northwest",
    "/players/catacomb/Cavern/rooms/lvl2_5.c","east",
    "/players/catacomb/Cavern/rooms/lvl2_7.c","south" 
  });
}
