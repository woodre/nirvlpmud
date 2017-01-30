/*                                                                    *
 *    File:             /players/angel/area/twilight/room/entrance.c  *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2007 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           06/15/07                                      *
 *    Notes:            Entrance                                      *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"

#include <ansi.h>

#include "/players/angel/area/stargate/obj/dial_obj.c"

inherit "room/room";

int x;

reset(arg)
{
  ::reset(arg);
  if(!present("dhd"))
     move_object(clone_object("/players/angel/area/atlantis/obj/dhd"), this_object());
  /*
  if( !present(" ", this_object()) )
  {
    for(x=0; x<3; x++)
    {
    move_object(clone_object(" "), this_object());
    }
}*/
if(arg) return;
  set_light(1);
  short_desc = "Twilight City Stargate";
  long_desc =
"    ~ Dirt Road ~\n\
    You have found a dirt road leading to the north.  It does\n\
not seem to be very travelled.  Off in the distance to the north,\n\
you can see the walls of a large city.  Part of the city appears\n\
to be covered with a dark cloud.  The surrounding area is nothing\n\
but fields of wheat.  The stargate is in the middle of this field.\n";

  items =
  ({
    " ",
    " ",
  });
  dest_dir =
  ({
  });
}