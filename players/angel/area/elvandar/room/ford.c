/*                                                                    *
 *    File:             /players/angel/area/elvandar/room/ford.c      *
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
  short_desc = "~ Stream Ford ~";
  long_desc =
"  The Elven River appears to dwindle in its volume of water,\n\
yet again, as the banks of the Forests creep back in and take\n\
control of the scenery.  The crystal clear waters are extremely\n\
shallow, however you can still see the smooth pebbles and colorful\n\
rocks on the water's bottom.  From this point on you must abandon\n\
the River and set forth on foot, through the Elven Forests to the\n\
City of Elvandar.  Next to the Elven Brook, which continues on\n\
towards the South, there are several small animal paths, barely\n\
noticeable, on the soft carpet of green.  To the North, the Elven\n\
River appears to expand and flow towards the Capital City of Migaard.\n";

  items =
  ({
    " ",
    " ",
  });
  dest_dir =
  ({
    "/players/angel/area/elvandar/room/stream",     "north",
	"/players/angel/area/elvandar/room/f_01",       "south",
  });
}