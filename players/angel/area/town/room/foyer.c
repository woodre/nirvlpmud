inherit "room/room";
/*                                                                    *
 *    File:             /players/angel/area/town/room/foyer.c         *
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

#include "/players/angel/area/stargate/obj/dial_obj.c"


reset(arg)
{
  ::reset(arg);
  if(!present("dhd"))
     move_object(clone_object("/players/angel/area/stargate/obj/dhd"), this_object());
  if(!present("marker"))
     move_object(clone_object("/players/angel/area/town/obj/sign_03"), this_object());
  if(arg) return;
  set_light(1);
  short_desc = BOLD+BLU+"Gas City"+NORM;
  long_desc =
"  Welcome to "+HIM+"Gas City"+NORM+".  It appears you are on I-69 and need\n\
to head west towards Gas City.  The I-69 highway travels north\n\
and south.  HWY 35 travels west into the town of Gas City.\n";
 
  items =
  ({
  "city",
  "A town that carries many shadows",
  "river",
  "It is a nice flowing river. Many people like to tube down it\n\
in the summer.",
  "people",
  "Towns people",
  "i-69",
  "a corridor that the federal government wants to extend from\n\
Indiana to Texas",
  "town",
  "A place where people live, it is lively",
  "corridor",
  "A large and long stretch of road",
  "road",
  "what you drive on, a paved road",
  "dhd",
  "You should try to 'view dhd'",
  "DHD",
  "You should try to 'view dhd'",

  });
  dest_dir =
  ({
    "/players/angel/area/town/room/hw_351",      "west",
  });
}
