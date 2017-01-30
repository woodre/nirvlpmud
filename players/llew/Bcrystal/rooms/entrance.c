#pragma strict_types

#include "/players/llew/Bcrystal/rooms/bc_rooms.h"


inherit "players/llew/Bcrystal/rooms/bcroom.c";

void reset(int arg)
{
   if (!arg)
   {
      /* Setup of description and exits. */
      short_desc = HIC + "Ceda Tfelit" + NORM;
      long_desc  = "     A small chamber opens in a crystal of blue with passages leading\n" +
                   " in several directions.\n" + 
                   "     The corridor of the crystal shaft is rough and unformed.  Bits of\n" +
                   "crystal dust cover the tunnel floor.  Scuffs among the dust show\n" +
                   "movement through the area, but how recent, one cannot tell.  Unpolished\n" +
                   "walls reflect the soft glow from tiny wisps of floating blue energy.\n" +
                   "     A swirling rift, about three inches in diameter, holds steady a few\n" +
                   "feet above the tunnel.  The energy particles flitter about , avoiding\n" +
                   "the portal.\n";
      items = 
      ({
         "scuffs", "The scuffs look like footprints of a bipedal humanoid creature",
         "rift", "The rift crackles aiwht energy.  It seems foreign to the environment,\n" +
                 "much different then the particles of blue energy",
         "chamber", "It looks to be a natural formation, or one created so long ago, time\n" +
                    "has worn away any evidence otherwise",
      });
      dest_dir =
      ({
         ROOM_PATH + "neutral08", "north",
         ROOM_PATH + "neutral09", "east",
         ROOM_PATH + "neutral12", "south",
         ROOM_PATH + "neutral14", "southwest",
         "/room/eastroad4", "rift",
      });  

    
      section = NEUTRAL;

      /* Monsters we want in this room. */
      npcs = (string *)"/players/llew/Bcrystal/populator"->populate(section);
   }
::reset(arg);
}
