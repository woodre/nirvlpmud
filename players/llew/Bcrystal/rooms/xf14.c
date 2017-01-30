#pragma strict_types

#include "/players/llew/Bcrystal/rooms/bc_rooms.h"


inherit "players/llew/Bcrystal/rooms/bcroom.c";

void reset(int arg)
{
   /* String array to use to retrieve a description. */
   string *temp_desc;

   if (!arg)
   {
      section = XETRA_FRONT;

      /* Setup of description and exits. */
      short_desc = CYN + "Tkial Xetra" + NORM;

      temp_desc = (string *)DESCRIPTOR->describe_room(section);

      long_desc  = temp_desc[0];
      temp_desc -= ({ temp_desc[0] });

      items = temp_desc;

      dest_dir =
      ({
         ROOM_PATH + "xf10", "northeast",
         ROOM_PATH + "xf15", "east",
         ROOM_PATH + "xf09", "northwest",
      });  

      /* Monsters we want in this room. */
      npcs = (string *)POPULATOR->populate(section);
   }
::reset(arg);
}
