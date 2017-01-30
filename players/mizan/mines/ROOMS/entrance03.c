inherit "/room/room.c";
#include "/obj/ansi.h"


void reset(int arg) 
{
   if(arg) return;
   set_light(1);
   
   short_desc = HIY + "[3]" + NORM + " Staging Area - Earwaxian Murder Pit";
   long_desc =
  "  Go down to kill stuff.\n";
  items = ({

    "floor",
    "The floor appears to be made of some fairly high quality bathroom tile.",

  });
  
  dest_dir = 
  ({
    "/players/mizan/mines/ROOMS/tublock03.c", "north",
  });

  set_no_clean(1);
}


