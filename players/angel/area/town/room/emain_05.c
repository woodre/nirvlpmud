/*                                                                    *
 *    File:             /players/angel/area/town/room/emain_05.c      *
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
  short_desc = "East Main & 5th";
  long_desc =
"    "+HIB+"East Main and Fifth"+NORM+".\n\
  This is the main street that goes through the middle of town.\n\
Most businesses are off of main street. It remains busy at all times\n\
of the day and night. During the day there is the hustle and bustle\n\
of business and at night the road stays busy with young kids cruising\n\
around town. There are elegant two story houses along this stretch of\n\
main street. To the northeast is the old west school which has been\n\
shut down.\n";

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
    "school",
    "The old west school seems to be shut down.  The doors are blocked,\n\
     and signs on the premises warn of asbestos danger.",
  });
  dest_dir =
  ({
    "/players/angel/area/town/room/emain_06", "east",
    "/players/angel/area/town/room/emain_04", "west",
    "/players/angel/area/town/room/west",     "school",
  });
}