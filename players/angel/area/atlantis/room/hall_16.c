/*                                                                    *
 *    File:             /players/angel/area/atlantis/room/hall_16.c   *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2007 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           08/15/07                                      *
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
if(arg) return;
  set_light(1);
  short_desc = "Hall";
  long_desc =
"    "+WHT+"~ Hall ~"+NORM+"\n\
"+HIB+"  Along these halls in this massive complex there is high tech\n\
equipment.  Anyone looking around would feel inept trying to\n\
figure out what all the screens are used for. Halls lead to many\n\
different areas of Atlantis. The lighting and all room functions\n\
turn on and off as people walk in and out of each room."+NORM+"\n";

  items =
  ({
    "equipment",
    "computerized panels with an unknown language",
    "screens",
    "computerized flat panels",
    "screen",
    "computerized flat panel",
    "lights",
    "The area is lit up but no noticeable fixtures",
    "lighting",
    "The area is lit up but no noticeable fixtures",
  });

  dest_dir =
  ({
	"/players/angel/area/atlantis/room/hall_17.c",     "north",
	"/players/angel/area/atlantis/room/hall_15.c",     "south",
    "/players/angel/area/atlantis/room/crm.c",          "east",
  });
}