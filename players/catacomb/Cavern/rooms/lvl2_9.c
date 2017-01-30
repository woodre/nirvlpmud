#include "/players/catacomb/misc/ansi.h"
#define TP this_player()

inherit "room/room";

reset(arg) 
{
  if(arg) return;
  set_light(1);

  short_desc ="Second level of the Durkor Caverns" ;
  long_desc =(
  "  Torches line the walls of the cavern.  A few small streams of\n"+
  "water trickle across the floors of cavern.  The sound is very\n"+
  "eerie.  It almost seems like the calm before the storm.  As the\n"+
  "water disappears so does the serenity.\n"); 

  items = ({
    "torches",
    "The light from the torches flicker off the walls",
    "torch",
    "The torch crackles in the silence",
    "wall",
    "The walls have several torches on them",
    "walls",
    "The walls have several torches on them",
    "streams",
    "Small streams of water trickle across the floor", 
    "stream",
    "Small streams of water trickle across the floor", 
    "water",
    "The water slowly trickles across the floor", 
  });

  dest_dir = ({
    "/players/catacomb/Cavern/rooms/lvl2_8.c","east",
    "/players/catacomb/Cavern/rooms/lvl2_10.c","northwest"
  });
}
