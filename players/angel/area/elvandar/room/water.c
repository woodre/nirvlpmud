/*                                                                    *
 *    File:             /players/angel/area/elvandar/room/water.c     *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2006 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           11/15/06                                      *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = "~ Elven Waterfall ~";
  long_desc =
"  The sounds of the crystal clear waters of the Elven River\n\
cascading over the ledge are almost deafening, you being to\n\
wonder if this journey will mark your final upon the lands.\n\
In the distance, at the base of the Water Fall you can see your\n\
impending doom, the sharp and jagged rocks which break the\n\
waters and casts up the mists. Perhaps now you should not have\n\
chosen the road not traveled, and proceeded to the East, towards\n\
the City of Elvandar, since you can not fight the rushing waters\n\
and your demise appears inevitable.  You let out one last shout\n\
of courage as you sink below the waters cold embrace.\n";

  items =
  ({
    " ",
    " ",
  });
  dest_dir =
  ({
    "/players/angel/area/elvandar/room/er_03",    "north",
  });
}