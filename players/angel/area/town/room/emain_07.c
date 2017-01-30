/*                                                                    *
 *    File:             /players/angel/area/town/room/emain_07.c      *
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
  if( !present("multi02", this_object()) )
    move_object(clone_object("/players/angel/area/town/npc/multi_02.c"), this_object());
  if(arg) return;
  set_light(1);
  short_desc = "East Main & 7th";
  long_desc =
"    "+HIB+"East Main and Seventh"+NORM+".\n\
  This is the main street that goes through the middle of town.\n\
Most businesses are off of main street. It remains busy at all times\n\
of the day and night. During the day there is the hustle and bustle\n\
of business and at night the road stays busy with young kids cruising\n\
around town. There is a Double Daves to the northwest.\n";
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
    "daves",
    "The best pizza resturant you'll ever eat in",
});
  dest_dir =
  ({
    "/players/angel/area/town/room/emain_08",     "east",
    "/players/angel/area/town/room/emain_06",     "west",
    "/players/angel/area/town/room/daves",        "daves",
  });
}