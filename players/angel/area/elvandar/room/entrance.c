/*                                                                    *
 *    File:             /players/angel/area/elevandar/room/rm.c       *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2006 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           11/15/06                                      *
 *    Notes:            Entrance                                      *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"

#include <ansi.h>

#include "/players/angel/area/stargate/obj/dial_obj.c"

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!present("dhd"))
     move_object(clone_object("/players/angel/area/atlantis/obj/dhd"), this_object());
  if(arg) return;
  set_light(1);
  short_desc = "~ River Mouth ~";
  long_desc =
"  This is where the Elven River flows into the Migaard River, which\n\
surrounds Thera's Capital City of Migaard.  In the distance to the\n\
in the middle of the River.  Fishing vessels, ships of war, and\n\
Northeast you can see Migaard's Wharves and Levee which extend out\n\
merchant ships can be seen just off the port side of the Levee,\n\
waiting their turn to unload their precious cargoes and depart upon\n\
their next voyage.  To the South the Elven River continues to flow on\n\
into the distance, towards the Tree City of Elvandar.\n";

  items =
  ({
    "",
    "",
  });
  dest_dir =
  ({
	"/players/angel/area/elvandar/room/er",   "south",
  });
}