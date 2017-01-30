inherit "/room/room.c";
#include "/obj/ansi.h"

void reset(int arg) 
{
   if(arg) return;
   set_light(1);
   
   short_desc = HIY + "[1]" + NORM + " Tublock One";
   long_desc =
   "  " + HIY + "[T U B L O C K   O N E]" + NORM + " \n"+
   "    This is level Tublock One within the Proving Grounds. A clearly printed\n"+
   "  sign indicates that on this level are creatures fit for even the\n"+
   "  newest of new players for combat. The large fabric banner waving over\n"+
   "  the southern entrance proclaiming this to be the entrance to the Level\n"+
   "  One Area within the Proving Grounds of the OverPowerLord.\n"+
   "  You can continue further down the hole for harder monsters, once you\n"+
   "  qualify for them, of course.\n\n"+
   "  " + HIY + "GO SOUTH AND DOWN TO KILL THINGS\n" +
   "  " + HIY + "GO DOWN FOR HARDER CRITTERS\n" +
   "  " + HIY + "GO UP FOR THE ENTRANCE PLAZA\n" + NORM;

  items = ({

    "sign",
    "New Players: Please proceed south into the Level One Area.",

  });
  
  dest_dir = 
  ({
    "/players/mizan/mines/ROOMS/entrance01.c", "south",
    "/players/mizan/mines/ROOMS/entrance.c", "up",
    "/players/mizan/mines/ROOMS/tublock02.c", "down",
  });

  set_no_clean(1);
  call_other("/players/mizan/mines/grids/L01_main.c","???");
}

init()
{
   ::init();
}


