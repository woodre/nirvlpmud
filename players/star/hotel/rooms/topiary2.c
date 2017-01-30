/*
 *      File:                 /players/star/rooms/topiary2.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2005 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               12/21/2005
 *      Notes:
 *      Change History:
 */

#include <ansi.h>
#include </players/star/defs.h>

inherit "/room/room";

reset(arg)
{
  ::reset(arg);
    if(!present("dog"))
      move_object(clone_object(HOTEL+"npcs/dog.c"),this_object());
    if(!present("rabbit"))
      move_object(clone_object(HOTEL+"npcs/rabbit.c"),this_object());
  if(arg) return;
  set_light(1);
  short_desc = "A Topiary";
  long_desc =
  "   The path from the hotel to the playground winds through a number\n"+
  "of hedge animals.  Someone has spent a good deal of time skillfully\n"+
  "trimming the hedges here to look like various animals scattered\n"+
  "between here and the the hotel.  The playground is just to the south,\n"+
  "and on the other side of it the ground drops off quickly to the valley\n"+
  "below.\n";

  items =
  ({
    "hotel",
    "The hotel looks like it has two stories and an attic.  It is large and\n"+
    "beautifully built, and painted completely white",
    "playground",
    "The playground contains swings, a slide, and what looks like a doll\n"+
    "house and some kind of pipe",
    "animals",
    "The hedges on the sides of the path have been skillfully trimmed to\n"+
    "look like animals",
    "hedges",
    "The hedges on the sides of the path have been skillfully trimmed to\n"+
    "look like animals",
    "valley",
    "The valley is deep and the autumn leaves are brightly colored",
    "leaves",
    "The leaves are shades of "+HIR+"red, "+HIY+"yellow, "+NORM+"and "+YEL+"orange"+NORM,
    "path",
    "The paved path runs from the hotel to the playground",
    "swings",
    "From here it looks like the swings may have been removed for the\n"+
    "winter",
    "slide",
    "This is a plain metal slide",
    "house",
    "The doll house looks large, but from here it is still hard to see\n"+
    "details",
    "pipe",
    "The large concrete pipe looks to be half buried in the ground",
  });
  dest_dir =
  ({
    HOTEL+"rooms/topiary1.c",     "north",
    HOTEL+"rooms/playground.c",   "south",
  });
}
