/*                                                                    *
 *    File:             /players/angel/area/thanagar/room/entrance    *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2007 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           11/15/07                                      *
 *    Notes:            Area Entrance                                 *
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
    for(x=0; x<2; x++)
    {
    move_object(clone_object(" "), this_object());
    }
}*/
if(arg) return;
  set_light(1);
  short_desc = "Thanagar Stargate";
  long_desc =
"  This is a high mountain top which ascends a steep mountainside.\n\
The area overlooks a hugh city below where Manhawk's can be seen\n\
flying all around.  Looking around their appears to be no path to\n\
the town below.  Ahh; what it would be like to fly in the air.\n\
You sense that something very strange is going on below.\n";

  items =
  ({
    " ",
    " ",
  });
  dest_dir =
  ({
  });
}