#pragma strict_types

#include "/players/llew/Bcrystal/rooms/bc_rooms.h"


inherit "players/llew/Bcrystal/rooms/bcroom.c";

void reset(int arg)
{
   if (!arg)
   {
      /* Setup of description and exits. */
      short_desc = HIC + "Ceda Tfelit" + NORM;
      long_desc  = "     The crystal room is bare of any thing but for the little disturbed\n" +
                   "dust lying on the floor.  The walls let in light clearly.  Tunnels lead\n" +
                   "away from the room in a few directions.\n";
      items = 
      ({
         "room", "The simple room is free of any distinguishing features",
         "dust", "The dust is a thin coat on the floor of the room",
         "walls", "The walls are clear enough to let in ample light from the crystal world",
         "tunnels", "The tunnels lead away to the east, southwest and west",

      });
      dest_dir =
      ({
         ROOM_PATH + "neutral10", "east",
         ROOM_PATH + "neutral12", "southwest",
         ROOM_PATH + "neutral07", "west",
      });  

    
      section = NEUTRAL;

      /* Monsters we want in this room. */
      npcs = (string *)"/players/llew/Bcrystal/populator"->populate(section);
   }
::reset(arg);
}
