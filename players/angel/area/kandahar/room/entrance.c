/*                                                                    *
 *    File:             /players/angel/area/kandahar/room/entrance.c  *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2006 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           07/08/08                                      *
 *    Notes:                                                          *
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
  short_desc = HIR+"Kandahar's Stargate"+NORM;
  long_desc =
"  ~A Tunnel~\n\
This is a dimly lit tunnel.  Light floods in from above showing a\n\
narrow staircase hewn from the rock.  The staircase leads up and\n\
appears to be the way out of this area.  The tunnel gets darker\n\
and narrower to the west.\n";

  items =
  ({
  });

  dest_dir =
  ({
  });
}