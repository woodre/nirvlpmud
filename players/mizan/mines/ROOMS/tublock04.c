inherit "/room/room.c";
#include "/obj/ansi.h"

void reset(int arg) 
{
   if(arg) return;
   set_light(1);
   
   short_desc = HIY + "[4]" + NORM + " Tublock Four";
   long_desc =
   "  " + HIY + "[T U B L O C K   F O U R]" + NORM + " \n"+
   "  Go south to kill stuff.\n";

  dest_dir = 
  ({
    "/players/mizan/mines/ROOMS/entrance04.c", "south",
    "/players/mizan/mines/ROOMS/tublock03.c", "up",
    "/players/mizan/mines/ROOMS/tublock05.c", "down",
  });

  set_no_clean(1);
  call_other("/players/mizan/mines/grids/L04_main.c","???");
}

init()
{
   ::init();
}


