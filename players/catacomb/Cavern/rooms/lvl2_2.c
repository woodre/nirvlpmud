#include "/players/catacomb/misc/ansi.h"
#define TP this_player()

inherit "room/room";

reset(arg) 
{
  if(arg) return;
  set_light(1);

  short_desc ="Second level of the Durkor Caverns" ;
  long_desc =(
  "  The narrow passage limits passage to only the east and west. The\n"+
  "torches provide ample light to navigate by.  The large rocks provide\n"+
  "cover for the Durkor scouts in the second layer of their caverns.\n"+
  "The Durkor are stealth personified.  Through many years of isolation\n"+
  "they have been able to hone their martial arts skill.\n"); 

  items = ({
    "passage",
    "The passage is very narrow with all of the rocks scattered around", 
    "torches",
    "The torches provide ample light to navigate by", 
    "torch",
    "The torch flickers sending the light scrambling about the rocks",
    "rocks",
    "Large rocks provide cover for the Durkor scouts",
    "rock",
    "The rock sits ready to impale anyone not paying attention",
  });

  dest_dir = ({
    "/players/catacomb/Cavern/rooms/lvl2_1.c","west",
    "/players/catacomb/Cavern/rooms/lvl2_3.c","northeast" 
  });
  
}

