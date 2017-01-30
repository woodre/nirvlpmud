inherit "/room/room.c";
#include "/obj/ansi.h"

void reset(int arg) 
{
   if(arg) return;
   set_light(1);
   
   short_desc = HIY + "[6]" + NORM + " Tublock Six";
   long_desc =
   "  " + HIY + "[T U B L O C K   S I X]" + NORM + " \n"+
   "  Go south to kill stuff.\n";

  dest_dir = 
  ({
    "/players/mizan/mines/ROOMS/entrance06.c", "south",
    "/players/mizan/mines/ROOMS/tublock05.c", "up",
    "/players/mizan/mines/ROOMS/tublock07.c", "down",
  });

  set_no_clean(1);
  call_other("/players/mizan/mines/grids/L06_main.c","???");
}

init()
{
   ::init();
}


