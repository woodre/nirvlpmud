inherit "/room/room.c";
#include "/obj/ansi.h"

void reset(int arg) 
{
   if(arg) return;
   set_light(1);
   
   short_desc = HIY + "[2]" + NORM + " Staging Area";
   long_desc =
   "    A cavernous chamber greets you, which has the looks and general demeanor\n"+
  "  of a modern train station. Placards and banners hanging about stress\n"+
  "  the importance of combat safety, understanding how 'wimpy' works, and\n"+
  "  a variety of inspirational quotes by the OverPowerLord himself.\n"+
  "  It appears that the stairway down is another giant chamber for where the\n"+
  "  actual combat is to be had and by heading north will bring you\n"+
  "  back to the tublock exits of the Proving Grounds.\n\n"+
  "  " + HIY + "GO DOWN TO KILL THINGS\n" +
  "  " + HIY + "GO NORTH TO EXIT\n" + NORM;

  items = ({

    "floor",
    "The floor appears to be made of some fairly high quality bathroom tile.",

  });
  
  dest_dir = 
  ({
    "/players/mizan/mines/ROOMS/tublock02.c", "north",
  });

  set_no_clean(1);
}

