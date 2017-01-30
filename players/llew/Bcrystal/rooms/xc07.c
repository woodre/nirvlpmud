#pragma strict_types

#include "/players/llew/Bcrystal/rooms/bc_rooms.h"


inherit "players/llew/Bcrystal/rooms/bcroom.c";

void reset(int arg)
{
   /* String array to use to retrieve a description. */
   string *temp_desc;

   if (!arg)
   {
      section = XETRA_CONTROL;

      /* Setup of description and exits. */
      short_desc = RED + "Taera Xetra" + NORM;

      temp_desc = (string *)DESCRIPTOR->describe_room(section);

      long_desc  = temp_desc[0];
      temp_desc -= ({ temp_desc[0] });

      items = temp_desc;

      dest_dir =
      ({
         ROOM_PATH + "xc01", "northeast",
         ROOM_PATH + "xc08", "east",
         ROOM_PATH + "xc15", "southeast",
      });  

      /* Monsters we want in this room. */
      npcs = (string *)POPULATOR->populate(section);
   }
::reset(arg);
}