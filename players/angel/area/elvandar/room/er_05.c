/*                                                                    *
 *    File:             /players/angel/area/elvandarroom/er_05.c      *
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
  short_desc = "~ Elven River ~";
  long_desc =
"  The crystal clear waters of the Elven River allow you to see the\n\
fish and other aquatic life forms as they go about their business in\n\
the water's depths.  To the North the River fills your vision in a\n\
beautiful horizon of glittering golden, silver, and crimson leaves\n\
dancing in the warm breezes.  To the East, the River continues to\n\
flow on towards the Elven City, as you squint into the bright\n\
sunlight you think you can make out the shapes and images of the\n\
Elven Forests, sacred land of the Long Lived.\n";

  items =
  ({
    " ",
    " ",
  });
  dest_dir =
  ({
    "/players/angel/area/elvandar/room/er_06",     "east",
	"/players/angel/area/elvandar/room/er_04",      "west",
  });
}