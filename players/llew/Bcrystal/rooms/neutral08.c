#pragma strict_types

#include "/players/llew/Bcrystal/rooms/bc_rooms.h"


inherit "players/llew/Bcrystal/rooms/bcroom.c";

void reset(int arg)
{
   if (!arg)
   {
      /* Setup of description and exits. */
      short_desc = HIC + "Ceda Tfelit" + NORM;
      long_desc  = "    A bulge in the tunnel opens to a small room.  The tunnel continues\n" +
                   "to the northwest and the south.  Sounds of crackling can be heard to the\n" +
                   "south.  Blue specks of energy waft along invisible currents across the\n" +
                   "room.\n";
      items = 
      ({
         "tunnel", "The tunnel has rough walls and floor",
         "specks", "The specks of energy pass through the walls as if they weren't there",

      });
      dest_dir =
      ({
         ROOM_PATH + "entrance", "south",
         ROOM_PATH + "neutral05", "northwest",
      });  

    
      section = NEUTRAL;

      /* Monsters we want in this room. */
      npcs = (string *)"/players/llew/Bcrystal/populator"->populate(section);
   }
::reset(arg);
}
