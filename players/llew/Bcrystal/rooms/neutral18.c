#pragma strict_types

#include "/players/llew/Bcrystal/rooms/bc_rooms.h"


inherit "players/llew/Bcrystal/rooms/bcroom.c";

void reset(int arg)
{
   if (!arg)
   {
      /* Setup of description and exits. */
      short_desc = HIC + "Ceda Tfelit" + NORM;
      long_desc  = "     Light sparkles all around the crystal cavern.  The light bounces\n" +
                   "off the crystal walls and shines through from the inner light of this\n" +
                   "world.  Whispy blue particles float around aimlessly, passing through\n" +
                   "the walls and floor with ease.   The crystal is very clear here.  It is\n" +
                   "like walking in the midst of blue ice.  The tunnel leaves to the north\n" +
                   "and the east.\n";
      items = 
      ({
         "crystal", "The crystal is smooth, yet seems to be a natural formation",
         "cavern",  "The cavern rises to ten feet in height and is somewhat circular with a\n" +
                    "fifteen foot diameter",
         "walls",   "The walls are clear enough to see deeper in, but deeper in is only\n" +
                    "more reflections",
         "particles", "The particles are tiny specks of flickering lights.  They dim and\n" +
                      "brighten",
                      

      });
      dest_dir =
      ({
         ROOM_PATH + "neutral14", "north",
         ROOM_PATH + "neutral16", "east",
      });  

    
      section = NEUTRAL;

      /* Monsters we want in this room. */
      npcs = (string *)"/players/llew/Bcrystal/populator"->populate(section);
   }
::reset(arg);
}
