#pragma strict_types

#include "/players/llew/Bcrystal/rooms/bc_rooms.h"


inherit "players/llew/Bcrystal/rooms/bcroom.c";

void reset(int arg)
{
   /* String array to use to retrieve a description. */
   string *temp_desc;

   if (!arg)
   {
      section = CHAOTI_CONTROL;

      /* Setup of description and exits. */
      short_desc = GRN + "Taera Chaoti" + NORM;

      temp_desc = (string *)DESCRIPTOR->describe_room(section);

      /* The first entry is the description. The rest are the items. */                        
      long_desc  = temp_desc[0];
      temp_desc -= ({ temp_desc[0] });

      items = temp_desc;

      dest_dir =
      ({
         ROOM_PATH + "cc05", "northeast",
         ROOM_PATH + "cc19", "south",
         ROOM_PATH + "cc11", "west",
         ROOM_PATH + "cc04", "northwest",
      });  

      /* Monsters we want in this room. */
      npcs = (string *)POPULATOR->populate(section);
   }
::reset(arg);
}