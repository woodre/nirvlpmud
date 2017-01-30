/*                                                                    *
 *    File:             /players/angel/area/atlantis/room/lq_03.c     *
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
"      "+WHT+"~ MCKAY'S LIVING QUARTERS ~"+NORM+"\n\
"+HIB+"  This is McKay's room. It is one huge open area. Since the Ancients\n\
themselves were human, accommodations could not have been more\n\
perfect for the members of the expedition from Earth. This quarters\n\
is for a families, However McKay utilizes the room to hold artifacts\n\
he finds around the city. The place is packed."+NORM+"\n";

  items =
  ({
    "artifacts",
    "many objects found in the city",
    "artifact",
    "many objects found in the city",
  });

  dest_dir =
  ({
	"/players/angel/area/atlantis/room/hall_08.c",     "west",
  });
}