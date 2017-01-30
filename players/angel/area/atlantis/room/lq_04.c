/*                                                                    *
 *    File:             /players/angel/area/atlantis/room/lq_04.c     *
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
"      "+WHT+"~ RONON'S LIVING QUARTERS ~"+NORM+"\n\
"+HIB+"  This is Ronon's room. It is one large open area. It is suited\n\
for a single occupant. It has a double bed and many different\n\
types of weapons mounted on the wall."+NORM+"\n";

  items =
  ({
    "bed",
    "several pillows and the sheets are scatered about",
    "wall",
    "they are full of weapons",
    "walls",
    "they are full of weapons",
    "weapons",
    "many hand weapons mounted to the wall",
  });

  dest_dir =
  ({
	"/players/angel/area/atlantis/room/hall_07.c",     "west",
  });
}