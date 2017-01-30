inherit "/room/room.c";
#include "/obj/ansi.h"

void reset(int arg) 
{
   if(arg) return;
   set_light(1);
   
   short_desc = HIY + "[7]" + NORM + " Tublock Seven";
   long_desc =
   "  " + HIY + "[T U B L O C K   S E V E N]" + NORM + " \n"+
   "  Go south to kill stuff.\n";

  dest_dir = 
  ({
    "/players/mizan/mines/ROOMS/entrance07.c", "south",
    "/players/mizan/mines/ROOMS/tublock06.c", "up",
    "/players/mizan/mines/ROOMS/tublock08.c", "down",
  });

  set_no_clean(1);
  call_other("/players/mizan/mines/grids/L07_main.c","???");
}

init()
{
   ::init();
}


