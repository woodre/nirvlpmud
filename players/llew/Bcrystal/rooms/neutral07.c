#pragma strict_types

#include "/players/llew/Bcrystal/rooms/bc_rooms.h"


inherit "players/llew/Bcrystal/rooms/bcroom.c";

void reset(int arg)
{
   if (!arg)
   {
      /* Setup of description and exits. */
      short_desc = HIC + "Ceda Tfelit" + NORM;
      long_desc  = "     A convergence of three tunnels to the west and north lead to this\n" +
                   "small pocket in the crystal.  The light is peaceful here, the light\n" +
                   "flickers as if seen through water.  A tiny medley of energy floats with\n" +
                   "the waves of light.\n";
      items = 
      ({
         "tunnels", "The slender tunnels lead to the north, northwest and west",
         "pocket", "The room is really only big enough to turn around to another tunnel",
         "light", "The calm light seems to sooth the energy that resides here",

      });
      dest_dir =
      ({
         ROOM_PATH + "neutral06", "north",
         ROOM_PATH + "neutral09", "west",
         ROOM_PATH + "neutral04", "northwest",
      });  

    
      section = NEUTRAL;

      /* Monsters we want in this room. */
      npcs = (string *)"/players/llew/Bcrystal/populator"->populate(section);
   }
::reset(arg);
}
