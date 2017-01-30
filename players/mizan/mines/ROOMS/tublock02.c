inherit "/room/room.c";
#include "/obj/ansi.h"

void reset(int arg) 
{
   if(arg) return;
   set_light(1);
   
   short_desc = HIY + "[2]" + NORM + " Tublock Two";
   long_desc =
   "  " + HIY + "[T U B L O C K   T W O]" + NORM + " \n"+
   "    This is level Tublock Two within the Proving Grounds. A banner hanging\n"+
   "  over the southern entrance to the Level Two Area proclaims that it\n"+
   "  is best for new players who have successfully managed to get the basics\n"+
   "  of combat skills under control, as the challenges are more difficult\n"+
   "  in this section.\n"+
   "  You can continue further down the hole for harder monsters, once you\n"+
   "  qualify for them, of course.\n\n"+
   "  " + HIY + "GO SOUTH AND DOWN TO KILL THINGS\n" +
   "  " + HIY + "GO DOWN FOR HARDER CRITTERS\n" +
   "  " + HIY + "GO UP FOR EASIER CRITTERS\n" + NORM;

  items = ({

    "sign",
    "New Players: Please proceed south into the Level Two Area.",

  });
  
  dest_dir = 
  ({
    "/players/mizan/mines/ROOMS/entrance02.c", "south",
    "/players/mizan/mines/ROOMS/tublock01.c", "up",
    "/players/mizan/mines/ROOMS/tublock03.c", "down",
  });

  set_no_clean(1);
  call_other("/players/mizan/mines/grids/L02_main.c","???");

}

init()
{
   ::init();
}


