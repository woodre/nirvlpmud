/*                                                                    *
 *    File:             /players/angel/area/room/stream.c             *
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
  short_desc = "~ Elven Stream ~";
  long_desc =
"  The Elven River appears to dwindle in its volume of water\n\
as the banks of the Forests slowly begin to creep back in and\n\
take control of the scenery.  The crystal clear waters are\n\
getting shallow, however you can still see the fish and various\n\
other life forms going about their business in the water's depths.\n\
To the North, the Elven River appears to expand and fill your\n\
vision in a beautiful horizon of glittering golden, silver, and\n\
crimson leaves dancing in the warm breezes.  To the South, the\n\
Stream continues towards a stone ledge which extends over and\n\
above the Stream, the entrance to the Elven Forest, and gateway\n\
to the City beyond.\n";

  items =
  ({
    " ",
    " ",
  });
  dest_dir =
  ({
    "/players/angel/area/elvandar/room/er_06",     "west",
	"/players/angel/area/elvandar/room/ford",      "south",
  });
}