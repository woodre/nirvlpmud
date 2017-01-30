/*                                                                    *
 *    File:             /players/angel/area/town/room/hw_354.c        *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2007 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           6/15/07                                       *
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
  short_desc = "Highway 35";
  long_desc =
"     "+HIC+"HW 35"+NORM+"\n\
  Highway 35 stretchs three miles into Gas City. Gas City's physical\n\
features consist of rolling prairies that drain to the Mississenwa\n\
River, and the area is one-fourth forested.  Much of the vegetation\n\
consists of cultivated farms and pasture land.  The large James Dean\n\
historical museum is seen off to the east of the Highway.  There are\n\
corn fields to north and south and there are two farm houses to the\n\
southeast and southwest.\n";

  items =
  ({
  "prairies",
  "An area of open rolling grassy land",
  "river",
  "The water is fast flowing and crystal clear",
  "farms",
  "These farms are filled with mile of corn stalks",
  "pasture land",
  "An area of the farm where the cows and pigs live",
  "land",
  "An area of the farm where the cows and pigs live",
  "pasture",
  "An area of the farm where the cows and pigs live",
  });
  dest_dir =
  ({
    "/players/angel/area/town/room/hw_353",     "east",
    "/players/angel/area/town/room/emain_10",   "west",
    "/players/angel/area/town/land/land_01",    "farm",
    "/players/angel/area/town/land/land_02",    "house",
  });
}