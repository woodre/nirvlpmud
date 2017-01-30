#pragma strict_types

#include "/players/llew/Bcrystal/rooms/bc_rooms.h"


inherit "players/llew/Bcrystal/rooms/bcroom.c";

void reset(int arg)
{

   if (!arg)
   {
      /* Setup of description and exits. */
      short_desc = HIC + "Ceda Tfelit" + NORM;
      long_desc  = "     A rough chamber opens up with many tunnels leading in various\n" +
                   "directions.  Particles of blue glowing light float around the room,\n" +
                   "passing through the walls effortlessly.  The sound of crackling comes\n" +
                   "from the tunnel to the northwest.\n";
      items = 
      ({
         "chamber", "The large chamber has a wide ceiling above giving the blue energy room\n" +
                    "to move around playfully",
         "tunnels", "The rough tunnels show signs of travel in the collected dust on the ground",
         "particles", "The blue particles fly in flocks, alone, and some hover in the air",

      });
      dest_dir =
      ({
         ROOM_PATH + "neutral09", "northeast",
         ROOM_PATH + "neutral06", "east",
         ROOM_PATH + "neutral16", "south",
         ROOM_PATH + "neutral14", "west",
         ROOM_PATH + "entrance",  "northwest",
      });  

    
      section = NEUTRAL;

      /* Monsters we want in this room. */
      npcs = (string *)"/players/llew/Bcrystal/populator"->populate(section);
   }
   ::reset(arg);
}
