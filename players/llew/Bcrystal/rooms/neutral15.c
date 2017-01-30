#pragma strict_types

#include "/players/llew/Bcrystal/rooms/bc_rooms.h"


inherit "players/llew/Bcrystal/rooms/bcroom.c";

void reset(int arg)
{
   if (!arg)
   {
      /* Setup of description and exits. */
      short_desc = HIC + "Ceda Tfelit" + NORM;
      long_desc  = "     The tunnels of blue crystal open into a larger room here as the\n" +
                   "way curves to the west.  The path to the west is different somehow.\n" +
                   "The ever present lights of blue don't seem to be affected darting to\n" +
                   "and fro.\n";
      items = 
      ({
         "tunnels", "The long tunnels are clear and warmly blue",
         "room", "The room is more of an expansion of the tunnel as it curves around",
         "path", "Not so much a path, but yet this tunnel has seen its share of passage",
         "lights", "The lights ignore any other physical presence, but yet perhaps they\n" +
                   "are somehow aware of the world inhabitants",
      });
      dest_dir =
      ({
         ROOM_PATH + "neutral11", "northeast",
         ROOM_PATH + "xf08", "west",
      });  

    
      section = NEUTRAL;

      /* Monsters we want in this room. */
      npcs = (string *)"/players/llew/Bcrystal/populator"->populate(section);
   }
::reset(arg);
}
