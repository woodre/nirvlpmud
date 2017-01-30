/*                                                                    *
 *    File:             /players/angel/area/elvandar/room/wf.c        *
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
  short_desc = "~ Western Fork ~";
  long_desc =
"Having decided to take the Western Fork of the Elven River you\n\
maneuver your canoe towards the source of the storm, in the distance\n\
you can see mists rising up from rocks along the sandy beach.  The\n\
water appears to be moving quite quickly almost as if something was\n\
reaching out and pulling it from the River and taking it someplace.\n\
You decide to beach your canoe on the banks of the River while you\n\
decide which way you shall proceed, towards the source of thunder,\n\
into the path of danger, or back towards the East, towards the calm\n\
quiet of the River.\n";

  items =
  ({
    " ",
    " ",
  });
  dest_dir =
  ({
    "/players/angel/area/elvandar/room/rf",      "east",
	"/players/angel/area/elvandar/room/er_03",   "west",
  });
}