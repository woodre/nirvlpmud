/*                                                                    *
 *    File:             /players/angel/area/town/room/hw_355.c        *
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
int x;

reset(arg)
{
  ::reset(arg);
  if( !present("multi02", this_object()) )
  {
    for(x=0; x<2; x++)
    {
    move_object(clone_object("/players/angel/area/town/npc/multi_02"), this_object());
    }
  }
  if(arg) return;
  set_light(1);
  short_desc = "Highway 35";
  long_desc =
"    "+HIC+"HW 35"+NORM+"\n\
  The road to the west is changes back to Highway 35 which leads\n\
to other towns. To the east the road changes into Main street.\n\
The only thing visible to the northwest is farm land.  To the south\n\
is the local laundromat.\n";

  items =
  ({
  "highway",
  "Highway 35 runs through Gas City connecting it to I-69.",     
  "towns",
  "There are several small towns closely located to Gas City\n\
but you can't see them from here",
  "laundry",
  "clothes or linens that have been or are to be laundered",
  "laundry mat",
  "This is a commercial laundering establishment",
  "street",
  "The road has been newly paved and appears to be rich black in color",
  "farm land",
  "land that is used to grow and harvest corn",
  "land",
  "ground that is used to grow and harvest corn",
  });
  dest_dir =
  ({
    "/players/angel/area/town/room/track_01",     "east",
    "/players/angel/area/town/room/hw_356",       "west",
    "/players/angel/area/town/room/laundry",      "laundry",
  });
}