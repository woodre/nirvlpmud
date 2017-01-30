inherit "/room/room.c";
#include "/obj/ansi.h"

void reset(int arg) 
{
   if(arg) return;
   set_light(1);
   
   short_desc = HIY + "[3]" + NORM + " Tublock Three";
   long_desc =
   "  " + HIY + "[T U B L O C K   T H R E E]" + NORM + " \n"+
   "    This is level Tublock Three within the Proving Grounds. \n"+
   "  There is a disgusting funk in the air, which sort of smells like wet dog.\n"+
   "  It is a disconcertingly familiar yet alien odor, and you have to actually\n"+
   "  fight the instinctive urge to vomit on your feet from the putrid stench.\n"+
   "  After a bit of looking around at the cavern wall before you, the\n"+
   "  realization sinks in that the odor is a mixture of wet sheep hides and\n"+
   "  some funky, creamy white liquid which is covered all over the walls.\n"+
   "  Some scratchiti proclaims this area as the home of Earwax, the molester\n"+
   "  of sheep and all goatlike animals. Use your discretion, adventurer...\n"+
   "  It is recommended that you are at least level 6 and of high stats to enter.\n\n"+
   "  " + HIY + "GO SOUTH AND DOWN TO KILL THINGS\n" +
   "  " + HIY + "GO DOWN FOR HARDER CRITTERS\n" +
   "  " + HIY + "GO UP FOR EASIER CRITTERS\n" + NORM;

  dest_dir = 
  ({
    "/players/mizan/mines/ROOMS/entrance03.c", "south",
    "/players/mizan/mines/ROOMS/tublock02.c", "up",
    "/players/mizan/mines/ROOMS/tublock04.c", "down",
  });

  set_no_clean(1);
  call_other("/players/mizan/mines/grids/L03_main.c","???");
}

init()
{
   ::init();
}


