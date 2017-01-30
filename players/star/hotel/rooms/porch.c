/*
 *      File:                 /players/star/rooms/porch.c
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
  short_desc = "The Overlook's Porch";
  long_desc =
  "   The porch of the Overlook stretches the entire length of the front\n"+
  "of the hotel.  There are a few rocking chairs scattered here and there\n"+
  "along the length of it.  From here, most of the grounds can be seen,\n"+
  "including the driveway, the parking area, a playground, a few hedge\n"+
  "animals and a path around to the side of the hotel.  The path to the\n"+
  "side is currently roped off.\n";

  items =
  ({
    "hotel",
    "All that can be seen of the hotel from here is part of the front,\n"+
    "which is painted white",
    "rocking chairs",
    "The rocking chairs are made of natural wood, all in various shades of\n"+
    "brown",
    "chairs",
    "The rocking chairs are made of natural wood, all in various shades of\n"+
    "brown",
    "grounds",
    "The grounds are immaculate and well kept",
    "driveway",
    "The driveway looks recently paved",
    "parking area",
    "The parking area has been repainted recently, and the lines stand out\n"+
    "brightly",
    "area",
    "The parking area has been repainted recently, and the lines stand out\n"+
    "brightly",
    "playground",
    "The playground looks like a lot of fun",
    "animals",
    "The hedges on the sides of the path have been skillfully trimmed to\n"+
    "look like animals",
    "path",
    "The path around to the side of the hotel is roped off",
  });
  dest_dir =
  ({
    HOTEL+"rooms/lobby.c",     "north",
    HOTEL+"rooms/parking.c",   "south",
  });
}
