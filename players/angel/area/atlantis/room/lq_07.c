/*                                                                    *
 *    File:             /players/angel/area/atlantis/room/lq_07.c     *
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
"      "+WHT+"~ ZELENKA'S LIVING QUARTERS ~"+NORM+"\n\
"+HIB+"  This is Zelenka's room. It is one huge open area. Since the Ancients\n\
themselves were human, accommodations could not have been more\n\
perfect for the members of the expedition from Earth. This quarters\n\
is for a families, However Zelenka keeps boxes of scientific research\n\
from Earth."+NORM+"\n";

  items =
  ({
    "boxes",
    "they are filed with research papers",
  });

  dest_dir =
  ({
	"/players/angel/area/atlantis/room/hall_13.c",     "west",
  });
}