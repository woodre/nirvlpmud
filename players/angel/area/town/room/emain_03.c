/*                                                                    *
 *    File:             /players/angel/area/town/room/emain_03.c      *
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
  if( !present("multi02", this_object()) )
    move_object(clone_object("/players/angel/area/town/npc/multi_02.c"), this_object());
  if(arg) return;
  set_light(1);
  short_desc = "East Main & 3rd";
  long_desc =
"    "+HIB+"East main and Third"+NORM+".\n\
  The center of town has more compact businesses in old, red brick,\n\
four story buildings. These buildings have been made historic\n\
facilities so they can never be bought and destroyed. This seems to\n\
be a small downtown from the 1940's or 50's. There is a Flower shop\n\
to the south and Tony Ray's home is to the northeast.\n";
  items =
  ({
    "shop",
    "A place to buy flower arrangements",
    "buildings",
    "Old, red brick, four story structures",
    "businesses",
    "Enterprises privately owned, formed to earn profit to increase\n\
     the wealth of their owners",
    "station",
    "A place to sale goods and gas",
    "home",
    "A nice two story brick house",
    "house",
    "A nice two story brick residence",
  });
  dest_dir =
  ({
    "/players/angel/area/town/room/emain_04",  "east",
    "/players/angel/area/town/room/emain_02",  "west",
    "/players/angel/area/town/room/flower",    "shop",
  });
}