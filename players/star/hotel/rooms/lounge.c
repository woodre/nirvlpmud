/*
 *      File:                 /players/star/rooms/lounge.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2005 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               11/05/2005
 *      Notes:
 *      Change History:
 */

#include <ansi.h>
#include </players/star/defs.h>

inherit "/room/room";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = "The Overlook Bar and Lounge";
  long_desc =
  "   The Overlook's lounge is spacious and almost as lush as the\n"+
  "ballroom.  There are booths along the walls for privacy and a few\n"+
  "small tables scattered around the middle of the room.  There are\n"+
  "chairs piled upside-down on the tables.  Across the room from the\n"+
  "batwing doors is the bar, which is lined with bar stools.  Behind the\n"+
  "bar are rows and rows of empty shelves which usually contain bottles\n"+
  "of alcohol.  There is also a large mirror behind the bar that reflects\n"+
  "most of the room.\n";

  items =
  ({
    "ballroom",
    "Looking back over the batwing doors you can see the empty ballroom",
    "booths",
    "The booths have high backs and deep red cushions",
    "tables",
    "The small tables are bare now for the off season",
    "chairs",
    "The chairs have deep red cushions to match the ones in the booths",
    "doors",
    "The batwing doors look like something out of an old Western saloon",
    "bar",
    "The highly polished surface of the bar gleams in the dim light",
    "stools",
    "Stools upholstered in deep red line the front of the bar",
    "shelves",
    "The shelves are empty, so if you're thirsty you're out of luck",
    "bottles",
    "Bottles?  What bottles?  The shelves are empty",
    "mirror",
    "When you look at the mirror you see yourself looking back, of course",
  });
  dest_dir =
  ({
    HOTEL+"rooms/ballroom.c",     "east",
  });

  if(!present("jack"))
    move_object(clone_object(HOTEL+"npcs/jack.c"),this_object());
}
