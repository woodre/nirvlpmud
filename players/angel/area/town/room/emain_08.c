/*                                                                    *
 *    File:             /players/angel/area/town/room/emain_08.c      *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2007 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           11/15/07                                      *
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
  short_desc = "East Main & 8th";
  long_desc =
"    "+HIB+"East Main and Eighth"+NORM+".\n\
  This is the main street that goes through the middle of town.\n\
Most businesses are off of main street. It remains busy at all times\n\
of the day and night. During the day there is the hustle and bustle\n\
of business and at night the road stays busy with young kids cruising\n\
around town. McCleaver's gas station is visible to the northeast.\n";
  items =
  ({
    "businesses",
    "There are many different business that keep the local economy going",
    "street",
    "Two way paved lanes with large sidewalks along the road",
    "town",
    "This is a small community",
    "road",
    "Two way paved lanes",
});
  dest_dir =
  ({
    "/players/angel/area/town/room/emain_09",   "east",
    "/players/angel/area/town/room/emain_07",   "west",
    "/players/angel/area/town/room/mccleaver",  "cleavers",
  });
}