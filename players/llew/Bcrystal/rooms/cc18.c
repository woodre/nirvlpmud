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
         ROOM_PATH + "cc11", "north",
         ROOM_PATH + "cc17", "west",
         ROOM_PATH + "cc10", "northwest",
      });  

      /* Monsters we want in this room. */
      npcs = (string *)POPULATOR->populate(section);
   }
::reset(arg);
}