/*
 *      File:                 /players/star/rooms/lobby.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2005 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               10/24/2005
 *      Notes:
 *      Change History:
 */

#include <ansi.h>
#include </players/star/defs.h>

inherit "/room/room";

reset(arg)
{
   ::reset(arg);
    if(!present("snun"))
      move_object(clone_object(HOTEL+"npcs/snun.c"),this_object());
    if(!present("gnun"))
      move_object(clone_object(HOTEL+"npcs/gnun.c"),this_object());
    if(!present("lnun"))
      move_object(clone_object(HOTEL+"npcs/lnun.c"),this_object());
   if(arg) return;
   set_light(1);
   short_desc = "The Lobby of the Overlook Hotel";
   long_desc = 
   "   The lobby of the Overlook is lush and rich looking.  There is a \n"+
   "fireplace on the west wall with a comfortable looking couch in front\n"+
   "of it.  Just to the right of the fireplace is a set of large double\n"+
   "doors that are propped open to show a large ballroom beyond.  Across\n"+
   "the lobby from the main entrance there is a check-in desk, an\n"+
   "elevator, and a wide staircase.  A small hallway branches off from \n"+
   "the lobby toward the east.\n";

   items =
   ({
      "fireplace",
      "The fireplace contains a warm and cozy fire",
      "couch",
      "The couch is a deep red color and looks like it is covered in velvet", 
      "doors",
      "The double doors look like that are solid oak.  They also look like \n"+
      "someone polishes them at least twice a week",
      "ballroom",
      "The ballroom is a little hard to see from here, but it looks very\n"+
      "fancy",
      "desk",
      "The desk is empty, the bell and registration book having been removed \n"+
      "at the end of the tourist season",
      "elevator",
      "The elevator is an antique, and does not look all that safe.  Perhaps \n"+
      "the stairs would be a better option",
      "staircase",
      "The staircase is wide and carpeted with a thick blue carpet",
      "stairs",
      "The staircase is wide and carpeted with a thick blue carpet",
      "hallway",
      "The hallway is narrow and not anywhere near as fancy as the rest of \n"+
      "the lobby area",
   });
   dest_dir =
   ({
      HOTEL+"rooms/hallway.c",    "east",
      HOTEL+"rooms/ballroom.c",   "west",
      HOTEL+"rooms/porch.c",      "south",
      HOTEL+"rooms/up_hall3.c",   "up",
   });
}
