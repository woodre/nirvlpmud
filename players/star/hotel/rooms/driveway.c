/*
 *      File:                 /players/star/rooms/driveway.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2005 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               11/29/2005
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
  short_desc = "A Driveway";
  long_desc =
  "   The driveway runs from the parking area to the road, and is narrow,\n"+
  "but more than wide enough for two cars to pass each other.  The roof\n"+
  "and upper story of the hotel can be seen from here.\n";

  items =
  ({
    "road",
    "The road is two twisting lanes",
    "roof",
    "The roof of the hotel is covered in grey shingles",
    "story",
    "The upper story of the hotel is white and lined with windows",
    "hotel",
    "The upper story of the hotel is white and lined with windows",
  });
  dest_dir =
  ({
    HOTEL+"rooms/parking.c",     "west",
    "/players/star/bubble.c",      "back",
  });

  if(!present("hotel sign"))
    move_object(clone_object("/players/star/hotel/objs/hotel_sign.c"),this_object());
}
