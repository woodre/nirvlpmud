#pragma strict_types

#include "/players/llew/Bcrystal/rooms/bc_rooms.h"


inherit "players/llew/Bcrystal/rooms/bcroom.c";

void reset(int arg)
{
   if (!arg)
   {
      /* Setup of description and exits. */
      short_desc = HIC + "Ceda Tfelit" + NORM;
      long_desc  = "     The crystal walls are smoother here.  The reflected light is blinding\n" +
                   "to the eyes.  The open space is filled with energy particles spinning and\n" +
                   "careening wildly.  The display is dazzling.\n";
      items = 
      ({
         "particles", "The particles dance wildly in a symphony of reflected light",
      });
      dest_dir =
      ({
         ROOM_PATH + "neutral07", "southwest",
         ROOM_PATH + "neutral02", "west",
      });  

    
      section = NEUTRAL;

      /* Monsters we want in this room. */
      npcs = (string *)"/players/llew/Bcrystal/populator"->populate(section);
   }
::reset(arg);
}
