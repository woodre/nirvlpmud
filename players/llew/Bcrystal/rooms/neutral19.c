#pragma strict_types

#include "/players/llew/Bcrystal/rooms/bc_rooms.h"


inherit "players/llew/Bcrystal/rooms/bcroom.c";

void reset(int arg)
{
   if (!arg)
   {
      /* Setup of description and exits. */
      short_desc = HIC + "Ceda Tfelit" + NORM;
      long_desc  = "     This dim room is cluttered with chips and bits of crystal.  The\n" +
                   "walls and ceiling show they are the cause of the clutter.  Chunks of\n" +
                   "crystal are missing from them.  Som blue lights float about, but otherwise\n" +
                   "this rooms hows hardly a sign of occupation.\n";
      items = 
      ({
         "room", "The room is old and visibly unused",
         "chips", "The small chips and bits or crystal still resonate with some inner light",
         "bits",  "The small chips and bits or crystal still resonate with some inner light",
         "walls", "The walls are rough from the fallen chunks of crystal",

      });
      dest_dir =
      ({
         ROOM_PATH + "neutral01", "northeast",
         ROOM_PATH + "neutral05", "east",
         ROOM_PATH + "neutral11", "south",
      });  

    
      section = NEUTRAL;

      /* Monsters we want in this room. */
      npcs = (string *)"/players/llew/Bcrystal/populator"->populate(section);
   }
::reset(arg);
}
