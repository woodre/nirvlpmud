/*
 *      File:                 /players/star/rooms/parking.c
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
  short_desc = "The Parking Lot of the Overlook Hotel";
  long_desc =
  "   The parking area is large and flat.  There are very few cars left\n"+
  "here as most of the visitors have already left in advance of the\n"+
  "coming winter.  On one side of the parking area stands the hotel, and\n"+
  "on the other side is the playground.  There are a few hedge animals\n"+
  "along the path between here and the playground, and beyond the\n"+
  "playground is a gorgeous mountain view.\n";

  items =
  ({
    "cars",
    "Most of the cars here, with the exception of an aging VW bug and a\n"+
    "rather plain pickup truck, are very nice",
    "bug",
    "The VW bug is red, and from the looks of it the thing likely just\n"+
    "barely made it up the mountain",
    "truck",
    "The pickup truck is white, and has the hotel's name and address\n"+
    "painted on the sides",
    "hotel",
    "The hotel looks like it has two stories and an attic.  It is large and\n"+
    "beautifully built, and painted completely white",
    "playground",
    "From here, all that can be seen of the playground is the top of the\n"+
    "swing set and the top of the slide.  The hedge animals are blocking\n"+
    "the view",
    "animals",
    "The animals include a rabbit and a couple of lions",
    "view",
    "You can see for miles from up here",
    "swing set",
    "It looks from here like the swings have been removed for the winter",
    "set",
    "It looks from here like the swings have been removed for the winter",
    "slide",
    "This is a plain metal slide",
    "path",
    "The paved path runs from the parking lot to the playground",
  });
  dest_dir =
  ({
    HOTEL+"rooms/porch.c",     "north",
    HOTEL+"rooms/driveway.c",  "east",
    HOTEL+"rooms/topiary1.c",  "south",
  });
}
