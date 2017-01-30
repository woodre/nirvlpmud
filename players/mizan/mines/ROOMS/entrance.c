inherit "/room/room.c";
#include "/obj/ansi.h"

void reset(int arg) 
{
   if(arg) return;
   set_light(1);
   
   short_desc = "Entrance to the Proving Grounds of the OverPowerLord";
   long_desc =
   "    " + HIB + ">>>" + NORM + " " + HIY + 
   "Welcome to the Proving Grounds of the OverPowerLord!"+ 
   NORM + " " + HIB + "<<<" + NORM + "\n" +
   "    Spread out before you is a large plaza that has the qualities of a\n" +
   "  gaudy Las Vegas casino combined with the hopeless optimism of Disney\n"+
   "  World mixed together. Large billboards proclaiming what lies below in\n"+
   "  the Mines of the OverPowerLord for eager adventurers clutter up the\n"+
   "  scenery, obscuring the trees and distant mountains. In the center of\n"+
   "  this plaza is a large portrait of the OverPowerLord himself, smiling\n"+
   "  maginamously at all who stand before it. You can't help but chuckle.\n"+
   "\n"+
   "    Your inner adventurer really wants to enter this place to see what\n" +
   "  violence and rewards lie ahead. Go down into the tublock, which is\n"+
   "  a fancy tunnel entrance to the realm below to kill things, or you can\n"+
   "  head north back to the village spine. To the east is a giant lounge\n"+
   "  and bar complex, and to the west is an open air mall carrying gear \n"+
   "  fit for adventurers of all levels and experience.\n\n"+
   "  " + HIY + "GO EAST FOR BOOZE\n" +
   "  " + HIY + "GO WEST FOR MERCH\n" +
   "  " + HIR + "GO DOWN TO KILL THINGS\n" + NORM + NORM;
   
  items = ({

    "floor",
    "The floor appears to be made of some fairly high quality granite slabs.\n"+
    "It really looks like some good stuff.",

    "portrait",
    "The broad and grinning smile of the OverPowerLord beckons you further\n"+
    "south, where the entrance to his proving grounds awaits.",

  });
  
  dest_dir = 
  ({
    "/players/mizan/mines/ROOMS/tublock01.c", "down",
    "/players/mizan/mines/ROOMS/giftshop.c", "west",
    "/players/mizan/mines/ROOMS/lounge.c", "east",
    "/room/wild1.c", "north",
  });

  set_no_clean(1);
}

init()
{
   ::init();
}

