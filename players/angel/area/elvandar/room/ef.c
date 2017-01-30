/*                                                                    *
 *    File:             /players/angel/area/room/ef.c                 *
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
  short_desc = "~ Eastern Fork ~";
  long_desc =
"  The crystal clear waters of the Elven River allow you to see the\n\
fish and other aquatic life forms as they go about their business\n\
in the water's depths.  To the West you can see the Fork of the Elven\n\
River, at which point the two halves of the River join together and\n\
continue to flow North towards the City of Migaard.  To the South the\n\
River continues to flow in a peaceful fashion, taking you slowly but\n\
surely to the Elven City.\n";

  items =
  ({
    " ",
    " ",
  });
  dest_dir =
  ({
    "/players/angel/area/elvandar/room/er_04",     "south",
	"/players/angel/area/elvandar/room/wf",        "west",
  });
}