#pragma strict_types

#include "/players/llew/Bcrystal/rooms/bc_rooms.h"


inherit "players/llew/Bcrystal/rooms/bcroom.c";

void reset(int arg)
{
   if (!arg)
   {
      /* Setup of description and exits. */
      short_desc = HIC + "Ceda Tfelit" + NORM;
      long_desc  = "     A circular room opens in the crystal with passages leading in many\n" +
                   "directions.  The light of the crystal world brightens the whole room.  The\n" +
                   "ground shows varied signs of a lot of feet passing by.  Energy bits seem\n" +
                   "to dance with the wavering light from thr walls.\n";
      items = 
      ({
         "room", "The room is larg, about twenty by twenty-five feet with the ceiling a good\n" +
                 "twenty feet up",
         "passages", "Many passages lead away from this room",
         "crystal", "The deep glow of the world shines through the crystal walls",
         "ground", "This section of crystal is a hub of activity from the look of the worn ground",
         "bits", "The bits' random flight looks like a dance of its own",

      });
      dest_dir =
      ({
         ROOM_PATH + "neutral07", "north",
         ROOM_PATH + "neutral10", "southeast",
         ROOM_PATH + "neutral12", "south",
         ROOM_PATH + "entrance",  "southwest",
         ROOM_PATH + "neutral03", "northwest",
      });  

    
      section = NEUTRAL;

      /* Monsters we want in this room. */
      npcs = (string *)"/players/llew/Bcrystal/populator"->populate(section);
   }
::reset(arg);
}
