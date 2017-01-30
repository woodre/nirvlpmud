/*                                                                    *
 *    File:             /players/angel/area/atlantis/room/lq.c        *
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
"      "+WHT+"~ SHEPPARD'S LIVING QUARTERS ~"+NORM+"\n\
"+HIB+"  This is Sheppard's room. It is one large open area. He has a couch\n\
in front of his bed with a large flat T.V. next to it.  Since the\n\
Ancients themselves were human, accommodations could not have been\n\
more perfect for the members of the expedition from Earth.  This\n\
quarters is suited for a single occupant."+NORM+"\n";

  items =
  ({
    "couch",
    "looks comfy, it fit three people",
    "tv",
    "56 inch flat screen",
    "bed",
    "it is a double bed and not well kept",
  });

  dest_dir =
  ({
	"/players/angel/area/atlantis/room/hall_07.c",     "east",
  });
}