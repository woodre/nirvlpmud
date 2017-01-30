#pragma strict_types

#include "/players/llew/Bcrystal/rooms/bc_rooms.h"


inherit "players/llew/Bcrystal/rooms/bcroom.c";

void reset(int arg)
{
   if (!arg)
   {
      /* Setup of description and exits. */
      short_desc = HIC + "Ceda Tfelit" + NORM;
      long_desc  = "    The crystal tunnels cross paths here in a small opening.  The walls\n" +
                   "are rough, but the floor shows much use.  The internal glow of the world\n" +
                   "is dimmer here.  The blue lights pass through walls regularly.\n";
      items = 
      ({
         "tunnels", "The rough tunnels let in little light",
         "paths", "The paths lead to the northwest, northeast, south and east.  The path to\n" +
                  "the east seems the most traveled",
         "floor", "The floor is worn down from much use.  The east tunnel is the most worn",
         "lights", "The lights seem rather busy, passing from wall to wall and into the crystal",
      });
      dest_dir =
      ({
         ROOM_PATH + "neutral05", "northeast",
         ROOM_PATH + "neutral14", "south",
         ROOM_PATH + "neutral15", "west",
         ROOM_PATH + "neutral19", "northwest",
      });  

    
      section = NEUTRAL;

      /* Monsters we want in this room. */
      npcs = (string *)"/players/llew/Bcrystal/populator"->populate(section);
   }
::reset(arg);
}
