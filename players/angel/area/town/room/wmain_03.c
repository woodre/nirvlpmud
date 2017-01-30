/*                                                                    *
 *    File:             /players/angel/area/town/room/wmain_03.c      *
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
  short_desc = "West Main & 3rd";
  long_desc =
"    "+HIB+"West Main and Third"+NORM+".\n\
  This is the center of old down town. These Hundred year old,\n\
four story, red brick buildings all have businesses filling their\n\
first floors.  These building have been made historic facilities\n\
so they can never be bought and destroyed.  This seems to be a\n\
small down town from the 1940's or 50's. Max's Barber Shop is\n\
towards the southeast.\n";

  items =
  ({
    "businesses",
    "There are many different businesses that keep the local economy going",
    "street",
	"It is a two lane road",
	"town",
	"It is a small quiet city where many people live",
  });
  dest_dir =
  ({
    "/players/angel/area/town/room/wmain_02",     "east",
    "/players/angel/area/town/room/track_01",     "west",
    "/players/angel/area/town/room/barber",       "barber",
  });
  move_object(clone_object("/players/angel/area/town/npc/multi_mover.c"), this_object());
}