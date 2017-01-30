/*                                                                    *
 *    File:             /players/angel/area/elvandar/room/greatc.c    *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2007 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           05/15/07                                      *
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
  short_desc = "~ Great Chambers ~";
  long_desc =
"  The walls of the Great Chambers have been formed from the\n\
branches of the ancient Oak, centuries upon centuries, the\n\
Spellweavers have applied their magics to shape and mold the\n\
branches as the Oak matured into what it is this day.  In the\n\
tradition and custom of the Elven people, there are no benches\n\
in the Great Chamber, since it would be considered an insult to\n\
the monarch dare anyone sit in their presence without their\n\
permission.  The walls of the Chambers are adorned with magnificent\n\
tapestries of golden oak leaves, the tabard of the Royal Court.\n\
From this point, you may go to the North, or South, into the\n\
Queen's Square.\n";

  items =
  ({
    " ",
    " ",
  });
  dest_dir =
  ({
    "/players/angel/area/elvandar/room/throne,     "north",
	"/players/angel/area/elvandar/room/qs",        "south",
  });
}