#pragma strict_types

#include "/players/llew/Bcrystal/rooms/bc_rooms.h"


inherit "players/llew/Bcrystal/rooms/bcroom.c";

void reset(int arg)
{
   if (!arg)
   {
      /* Setup of description and exits. */
      short_desc = HIC + "Ceda Tfelit" + NORM;
      long_desc  = "     Three tunnels converge on an oval shaped room.  The floor dips\n" +
                   "down in a bowl shaped depression, collecting chips and bits of crystal\n" +
                   "at the bast of the room.  The light is calm and peaceful.  A few blue\n" +
                   "particles meander aimlessly.\n";
      items =
      ({
         "tunnels", "The three tunnels converge into the room from the north, though the\n" +
                    "path to the northeast seems to be the most traveled",
         "room", "The room is spacious enough to hold several people comfortably",
         "floor", "The ground is rough enough to keep a sure footing in the room",
         "light", "The light flickers in this room, like a blue candle flame in a breeze",
         "particles", "The blue particles seem almost lazy, floating about",
      });
      dest_dir =
      ({
         ROOM_PATH + "neutral10", "north",
         ROOM_PATH + "neutral13", "northeast",
         ROOM_PATH + "neutral16", "northwest",
      });  

    
      section = NEUTRAL;

      /* Monsters we want in this room. */
      npcs = (string *)"/players/llew/Bcrystal/populator"->populate(section);
   }
::reset(arg);
}
