#pragma strict_types

#include "/players/llew/Bcrystal/rooms/bc_rooms.h"


inherit "players/llew/Bcrystal/rooms/bcroom.c";

void reset(int arg)
{
   if (!arg)
   {
      /* Setup of description and exits. */
      short_desc = HIC + "Ceda Tfelit" + NORM;
      long_desc  = "     This intersection in the crystal tunnels is less traveled than others.\n" + 
                   "Crumbling bits of crystal along the wall are ready to break, falling to\n" +
                   "the floor to join the piles already there.\n" +
                   "     Blue lights zip about, gliding along the walls as much as passing\n"+
                   "through them.  A mass of them spin around in conjunction near the ceiling.\n";
      items = 
      ({
         "bits", "Piles of the bits have collected near the rounded walls over great time",
         "piles", "Rummaging through the piles shows the smooth floor beneath",
         "lights", "The lights move about playfully, seemingly ignorant of any other presence.\n",
         "mass", "It is uncertain what would cause such a display in this location",
      });
      dest_dir =
      ({
         ROOM_PATH + "neutral03", "southeast",
         ROOM_PATH + "neutral05", "south",
         ROOM_PATH + "neutral19", "west",
      });  

    
      section = NEUTRAL;

      /* Monsters we want in this room. */
      npcs = (string *)"/players/llew/Bcrystal/populator"->populate(section);
   }
::reset(arg);
}
