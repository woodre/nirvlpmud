#pragma strict_types

#include "/players/llew/Bcrystal/rooms/bc_rooms.h"


inherit "players/llew/Bcrystal/rooms/bcroom.c";

void reset(int arg)
{
   if (!arg)
   {
      /* Setup of description and exits. */
      short_desc = HIC + "Ceda Tfelit" + NORM;
      long_desc  = "     Large mounds of crystal are piled in the middle of this collapsed\n" +
                   "chamber.  The small room has been damaged recently, causing the ceiling\n" +
                   "to break under the pressure of the crystal world.  Blue lights zip and\n" +
                   "zing near into the rubble.\n";
      items = 
      ({
         "mounds", "Four piles of crystal chunks are on the floor.  They look safe enough",
         "crystal", "The blue crystal emits a soft blue glow",
         "chamber", "The chamber seems safe enough to pass through.  Whatever danger there\n" +
                    "was has already spent itself",
         "lights", "The particles of light seem to be aggrivated by the fallen crystal",
         "rubble", "Four piles of crystal chunks are on the floor.  They look safe enough",
      });
      dest_dir =
      ({
         ROOM_PATH + "neutral12", "north",
         ROOM_PATH + "neutral17", "east",
         ROOM_PATH + "neutral18", "southwest",
      });  

    
      section = NEUTRAL;

      /* Monsters we want in this room. */
      npcs = (string *)"/players/llew/Bcrystal/populator"->populate(section);
   }
::reset(arg);
}
