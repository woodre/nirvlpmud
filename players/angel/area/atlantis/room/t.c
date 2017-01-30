/*                                                                    *
 *    File:             /players/angel/area/atlantis/room/t.c         *
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
  if(!present("halling"))
     move_object(clone_object("/players/angel/area/atlantis/npc/halling.c"), this_object());
if(arg) return;
  set_light(1);
  short_desc = "Terrace";
  long_desc =
"      "+WHT+"~ Terrace ~"+NORM+"\n\
"+HIB+"  This terrace overlooks a large, beautiful blue ocean side.\n\
Looking out there is nothing in sight except the clear blue\n\
water. A serene feeling is all about."+NORM+"\n";

  items =
  ({
    "ocean",
    "all that can be seen is open blue waters",
    "terrace",
    "it is like a porch with metal rails with a view of the ocean",
  });

  dest_dir =
  ({
	"/players/angel/area/atlantis/room/hall_09.c",     "south",
  });
}