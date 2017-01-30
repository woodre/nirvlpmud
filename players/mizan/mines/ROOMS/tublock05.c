inherit "/room/room.c";
#include "/obj/ansi.h"

void reset(int arg) 
{
   if(arg) return;
   set_light(1);
   
   short_desc = HIY + "[5]" + NORM + " Tublock Five";
   long_desc =
   "  " + HIY + "[T U B L O C K   F I V E]" + NORM + " \n"+
   "  Go south to kill stuff.\n";

  dest_dir = 
  ({
    "/players/mizan/mines/ROOMS/entrance05.c", "south",
    "/players/mizan/mines/ROOMS/tublock04.c", "up",
    "/players/mizan/mines/ROOMS/tublock06.c", "down",
  });

  set_no_clean(1);
  call_other("/players/mizan/mines/grids/L05_main.c","???");
}

init()
{
   ::init();
}


