#pragma strict_types

#include "/players/llew/Bcrystal/rooms/bc_rooms.h"


inherit "players/llew/Bcrystal/rooms/bcroom.c";

void reset(int arg)
{
   if (!arg)
   {
      /* Setup of description and exits. */
      short_desc = HIC + "Ceda Tfelit" + NORM;
      long_desc  = "     Many tunnels lead to this junction in the crystal.  The room opens\n" + 
                   "opens widely, the light from the tunnels pouring forth to brighten it.\n" +
                   "The ground here looks well trodden from traffic.\n";
      items = 
      ({
         "tunnels", "The narrow tunnels lead away from this junction in the tunnels",
         "crystal", "The blue shining crystal here seems full of energy.\n",
         "room", "The floor is smooth and clear",
         "ground", "The ground looks as smooth as the walls",
      });
      dest_dir =
      ({
         ROOM_PATH + "neutral01", "north",
         ROOM_PATH + "neutral03", "northeast",
         ROOM_PATH + "neutral08", "south",
         ROOM_PATH + "neutral14", "southwest",
         ROOM_PATH + "neutral11", "west",
         ROOM_PATH + "neutral19", "northwest",
      });  

    
      section = NEUTRAL;

      /* Monsters we want in this room. */
      npcs = (string *)"/players/llew/Bcrystal/populator"->populate(section);
   }
::reset(arg);
}
