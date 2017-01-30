/*                                                                    *
 *    File:             /players/angel/area/town/room/wmain_02.c      *
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
  short_desc = "West Main & 2nd";
  long_desc =
"    "+HIB+"West Main and Second"+NORM+".\n\
  This is the center of old down town. These Hundred year old,\n\
four story, red brick buildings all have businesses filling their\n\
first floors.  These building have been made historic facilities so\n\
they can never be bought and destroyed.  This seems to be a small\n\
down town from the 1940's or 50's. The Hatfield Flea Market is\n\
towards the northeast.\n";

  items =
  ({
    "businesses",
    "There are many different business that keep the local economy going",
    "street",
	"It is a two lane road",
	"town",
	"It is a small quiet city where many people live",
  });
  dest_dir =
  ({
    "/players/angel/area/town/room/main_01",      "east",
    "/players/angel/area/town/room/wmain_03",     "west",
    "/players/angel/masons/room/pub",             "pub",
    "/players/angel/area/town/room/market",       "market",
  });
}