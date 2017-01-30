#include "/players/catacomb/misc/ansi.h"
#define TP this_player()

inherit "room/room";

reset(arg) 
{
  if(arg) return;
  set_light(1);

  short_desc ="Second level of the Durkor Caverns" ;
  long_desc =(
  "  The rocks to north look as if they can only be navigated by\n"+
  "climbing through them.  The shadows are all around the cavern.\n"+
  "They seem to close and then return to their original position\n"+
  "only to begin closing in again.  Muffled chanting can be heard\n"+
  "to the west.\n"); 

  items = ({
    "rocks",
    "The rocks to the north force you to 'climb' to get through them",
    "rock",
    "The rocks to the north force you to 'climb' to get through them",
    "shadows",
    "The shadows flutter about the room",
    "shadow",
    "The shadows flutter about the room",
    "cavern",
    "The cavern is engulfed in eerie shadows"

  });

  dest_dir = ({
    "/players/catacomb/Cavern/rooms/lvl2_12.c","west",
    "/players/catacomb/Cavern/rooms/lvl2_10.c","climb"
  });
}
