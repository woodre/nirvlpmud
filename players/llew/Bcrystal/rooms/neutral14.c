#pragma strict_types

#include "/players/llew/Bcrystal/rooms/bc_rooms.h"


inherit "players/llew/Bcrystal/rooms/bcroom.c";

void reset(int arg)
{
   if (!arg)
   {
      /* Setup of description and exits. */
      short_desc = HIC + "Ceda Tfelit" + NORM;
      long_desc  = "    The ground here is very flat, looking like it was carved by some\n" +
                   "intelligent creature.  Many tunnels lead away out of the corners of\n" +
                   "the room.  The walls rise up rough and natural.  The soft blue glow of\n" +
                   "the crystal world fills the room.\n";
      items = 
      ({
         "ground", "The ground is smooth and level and even clean",
         "tunnels", "While the room is obviously affected by an outside source, the tunnel\n" +
                    "are very natural",
         "corners", "The rounded room's corners are not really such, as there are holes of\n" +
                    "the passages away", 
         "walls", "The walls allow the light of the world to illuniate the room",

      });
      dest_dir =
      ({
         ROOM_PATH + "neutral05", "north",
         ROOM_PATH + "entrance",  "northeast",
         ROOM_PATH + "neutral12", "east",
         ROOM_PATH + "neutral18", "south",
         ROOM_PATH + "neutral11", "northwest",
      });  

    
      section = NEUTRAL;

      /* Monsters we want in this room. */
      npcs = (string *)"/players/llew/Bcrystal/populator"->populate(section);
   }
::reset(arg);
}
