/*                                                                    *
 *    File:             /players/angel/area/atlantis/room/lq_05.c     *
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

reset(arg)
{
  ::reset(arg);
if(arg) return;
  set_light(1);
  short_desc = "LIVING QUARTERS";
  long_desc =
"      "+WHT+"~ TEYLA'S LIVING QUARTERS ~"+NORM+"\n\
"+HIB+"  This is Teyla's room. It is one large open area. There is a double\n\
bed on the west wall.There are many artifacts from Teyla's home world\n\
filling the shelves around the room. This room is suited for a single\n\
occupant."+NORM+"\n";

  items =
  ({
    "bed",
    "It is neat and tidy",
    "wall",
    "there filled with shelves",
    "shelves",
    "they are filled with items from Athos",
    "artifacts",
    "objects from Athos",
    "artifact",
    "an object from Athos",
  });

  dest_dir =
  ({
	"/players/angel/area/atlantis/room/hall_13.c",     "east",
  });
}