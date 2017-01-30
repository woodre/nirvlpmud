#pragma strict_types

#include "/players/llew/Bcrystal/rooms/bc_rooms.h"


inherit "players/llew/Bcrystal/rooms/bcroom.c";

void reset(int arg)
{
   if (!arg)
   {
      /* Setup of description and exits. */
      short_desc = HIC + "Ceda Tfelit" + NORM;
      long_desc  = "     The small bulge in the tunnel is dark.  The walls are thicker, rough,\n" +
                   "not letting as much of the internal blueish glow of the crystal in.  Less\n" + 
                   "of the tiny floating lights are present, but the few that are go about\n" +
                   "their choatic flight as normal.\n";
      items = 
      ({
         "bulge", "The room is a little bigger than the tunnels that cut back on each other",
         "lights", CYN + "*               *          *              *" + NORM
      });
      dest_dir =
      ({
         ROOM_PATH + "neutral04", "southeast",
         ROOM_PATH + "neutral03", "south",
      });  

    
      section = NEUTRAL;

      /* Monsters we want in this room. */
      npcs = (string *)"/players/llew/Bcrystal/populator"->populate(section);
   }
::reset(arg);
}
