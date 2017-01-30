/*                                                                            *
 *      File:             /players/angel/area/town/room/emain_02.c            *
 *      Function:         room                                                *
 *      Author(s):        Angel@Nirvana                                       *
 *      Copyright:        Copyright (c) 2006 Angel                            *
 *                                All Rights Reserved.                        *
 *      Source:           11/20/06                                            *
 *      Notes:                                                                *
 *                                                                            *
 *                                                                            *
 *      Change History:                                                       *
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
  short_desc = "East Main & 2nd";
  long_desc =
"    "+HIB+"East main and Second"+NORM+". \n\
  The center of town has more compact businesses in old, red brick,\n\
four story buildings. These buildings have been made historic\n\
facilities so they can never be bought and destroyed. This seems to\n\
be a small downtown from the 1940's or 50's. The Handy Andy gas\n\
station is on the corner to the south and the new CVS pharmacy is\n\
towards the northeast.\n";
  items =
  ({
    "Handy Andy",
    "A small convenient store that is a part of a small chain",
    "pharmacy",
    "A place to purchase medicine",
    "buildings",
    "Old, red brick, four story structures",
    "businesses",
    "Enterprises privately owned, formed to earn profit to increase\n\
     the wealth of their owners",
    "station",
    "A place to sale goods and gas",
  });
  dest_dir =
  ({
    "/players/angel/area/town/room/emain_03",   "east",
    "/players/angel/area/town/room/main_01",    "west",
    "/players/angel/area/town/room/cvs",        "cvs",
    "/players/angel/area/town/room/handyandy",  "station",
  });
}