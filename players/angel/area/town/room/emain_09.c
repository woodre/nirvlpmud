/*                                                                    *
 *    File:             /players/angel/area/town/room/emain_09.c      *
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
    for(x=0; x<3; x++)
    {
    move_object(clone_object("/players/angel/area/town/npc/multi_02"), this_object());
    }
  }
  if(arg) return;
  set_light(1);
  short_desc = "East Main & 9th";
  long_desc =
"    "+HIB+"East Main and Ninth"+NORM+".\n\
  This is the main street that goes through the middle of town.\n\
Most businesses are off of main street. It remains busy at all times\n\
of the day and night. During the day there is the hustle and bustle\n\
of business and at night the road stays busy with young kids cruising\n\
around town. The local Mcdonalds can be seen towards the south.\n";

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
    "Mcdonalds",
    "A fast food restaurant chain",
  });
  dest_dir =
  ({
    "/players/angel/area/town/room/emain_10",      "east",
    "/players/angel/area/town/room/emain_08",      "west",
    "/players/angel/area/town/room/mcdonalds",     "mcds",
  });
}