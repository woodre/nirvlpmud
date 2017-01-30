/*                                                                    *
 *    File:             /players/angel/area/elevandar/room/er_02.c    *
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
"  The crystal clear waters of the Elven Rive allow you to see the\n\
fish and various other aquatic life forms as they go about their\n\
business in the water's depths.  Stone ledges and out croppings on\n\
either side of the River prevent you from beaching your canoe and\n\
exploring the wonders of the Elven Forests.  Beautiful trees with\n\
leaves of gold, crimson, silver, and emerald appear to sway from\n\
side to side in the warm breeze, almostif they were alive and\n\
dancing to the forests beautiful music  To the North the you can\n\
see the City of Migaard, getting smaller and smaller in the\n\
distance as you travel to the South, to Elvandar.\n";

  items =
  ({
    " ",
    " ",
  });
  dest_dir =
  ({
    "/players/angel/area/elvandar/room/er",     "north",
	"/players/angel/area/elvandar/room/rf",     "south",
  });
}