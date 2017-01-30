#pragma strict_types

#include "/players/llew/Bcrystal/rooms/bc_rooms.h"


inherit "players/llew/Bcrystal/rooms/bcroom.c";

void reset(int arg)
{
   if (!arg)
   {
      /* Setup of description and exits. */
      short_desc = HIC + "Ceda Tfelit" + NORM;
      long_desc  = "     The walls of this room are very rough.  Little light from the world\n" +
                   "penetrates the walls.  There is a disctinc lack of blue energies in the\n" +
                   "that also contributes to the dimness.  Tunnels leave in several directions.\n";
      items = 
      ({
         "walls", "The walls are very rough here.  On closer inspection, the roughness doesn't\n" +
                  "look natural",
         "room", "The room is small, barely an extension of the tunnel crossing",
         "tunnels", "The tunnels lead of to the northeast, east, south and west.  The eastern\n" +
                    "passage looks more traveled than the rest",

      });
      dest_dir =
      ({
         ROOM_PATH + "neutral06", "northeast",
         ROOM_PATH + "neutral13", "east",
         ROOM_PATH + "neutral17", "south",
         ROOM_PATH + "neutral09", "west",
      });  

    
      section = NEUTRAL;

      /* Monsters we want in this room. */
      npcs = (string *)"/players/llew/Bcrystal/populator"->populate(section);
   }
::reset(arg);
}
