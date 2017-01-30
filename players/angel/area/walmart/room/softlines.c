/*                                                                              *
 *      File:             /players/angel/area/walmart/room/softlines.c          *
 *      Function:         room                                                  *
 *      Author(s):        Angel@Nirvana                                         *
 *      Copyright:        Copyright (c) 2006 Angel                              *
 *                                All Rights Reserved.                          *
 *      Source:           11/15/06                                              *
 *      Notes:                                                                  *
 *                                                                              *
 *                                                                              *
 *      Change History:                                                         *
 */

#include <ansi.h>

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = HIR+"Softlines Isle"+NORM;
  long_desc =
"  "+HIR+"Softlines"+NORM+"\n\
This isle leads through the middle of the Softlines department.\n\
We've got just the right styles for men, women and children, from\n\
high-fashion finds to everyday basics. And always at Every Day Low\n\
Prices. You may browse all of the different departments but, "+HIR+"BEWARE"+NORM+"\n\
of the "+HIM+"strange happenings!"+NORM+" People keep reporting odd sightings in\n\
the clothing departments!\n\
There is a flier hanging on the wall that you can 'look' at!\n";

  items =
  ({
    "isle",
    "this is a long open corridor",
    "softlines",
    "A group of areas that carry clothing merchandise",
    "departments",
    "This is different areas of the store that sell merchandise\n\
that is unique to that area!",
    "people",
    "They are Wal-Mart customers!",
    "clothing",
    "Fabric or material formed by weaving, knitting, pressing,\n\
or felting natural or synthetic fibers",
    "flier",
    "Over the past couple of weeks customers have been reporting\n\
that they have seen some unusual things happen through out the\n\
store. We had one customer say he saw a mannequin jump off its\n\
stand and run back to receiving. Another customer stated that she\n\
saw an orange grow very large in just seconds and just roll to the\n\
back of the store. SO, BEWARE of what you may see it might attack!",

  });
  dest_dir =
  ({
    "/players/angel/area/walmart/room/mens",    "mens",
    "/players/angel/area/walmart/room/womens",  "womens",
    "/players/angel/area/walmart/room/boys",    "boys",
    "/players/angel/area/walmart/room/girls",   "girls",
    "/players/angel/area/walmart/room/jrs",     "jrs",
    "/players/angel/area/walmart/room/plus",    "plus",
    "/players/angel/area/walmart/room/isle",    "aisle",
  });
}

realm(){ return "NT"; }