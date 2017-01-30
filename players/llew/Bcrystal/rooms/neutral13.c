#pragma strict_types

#include "/players/llew/Bcrystal/rooms/bc_rooms.h"


inherit "players/llew/Bcrystal/rooms/bcroom.c";

void reset(int arg)
{

   if (!arg)
   {
      /* Setup of description and exits. */
      short_desc = HIC + "Ceda Tfelit" + NORM;
      long_desc  = "     This square room inside the blue crystal is clearly not a natural\n" +
                   "formation.  The walls are almost exactly square, but for some bits of the\n" +
                   "crystal walls gathering on the floor.  The western passages are usual, but\b" +
                   "the one to the east is unexplainably different.\n";
      items = 
      ({
         "room", "The room is almost a cube, except for the three passages and some bits of\n" +
                 "crystal lying about the floor",
         "walls", "The smooth crystal amkes this room brighter than other tunnels",
         "bits", "The crystal chips look sharp",
         "floor", "The floor is very flat, yet no reflection shows on its surface",
         "passages", "The all look normal, but the east passage goes somewhere different",

      });
      dest_dir =
      ({
         ROOM_PATH + "cf17", "east",
         ROOM_PATH + "neutral17", "west",
         ROOM_PATH + "neutral10", "northwest",
      });  

    
      section = NEUTRAL;

      /* Monsters we want in this room. */
      npcs = (string *)"/players/llew/Bcrystal/populator"->populate(section);
   }
   ::reset(arg);
}
