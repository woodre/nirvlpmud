#pragma strict_types

#include "/players/llew/Bcrystal/rooms/bc_rooms.h"


inherit "players/llew/Bcrystal/rooms/bcroom.c";

void reset(int arg)
{
   if (!arg)
   {
      /* Setup of description and exits. */
      short_desc = HIC + "Ceda Tfelit" + NORM;
      long_desc  = "     A larger room opens up with a natural rising ceiling.  A formation" +
                   "of blue lights dance about the crystal room playfully.  The floor shows\n" +
                   "little sign of traffic, but many tunnels lead away from the room.\n";
      items = 
      ({
         "ceiling", "The walls curve upwards into the rough ceiling, providing an open space\n" +
                    "for the lights",
      });
      dest_dir =
      ({
         ROOM_PATH + "neutral01", "north",
         ROOM_PATH + "neutral02", "east",
         ROOM_PATH + "neutral09", "southeast",
         ROOM_PATH + "neutral05", "south",
      });  

    
      section = NEUTRAL;

      /* Monsters we want in this room. */
      npcs = (string *)"/players/llew/Bcrystal/populator"->populate(section);
   }
::reset(arg);
}
