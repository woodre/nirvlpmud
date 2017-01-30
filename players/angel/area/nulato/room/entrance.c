/*                                                                    *
 *    File:             /players/angel/area/nulato/room/entrance.c    *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2007 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           06/15/07                                      *
 *    Notes:                                                          *
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
/*if( !present(" ", this_object()) )
  {
    for(x=0; x<3; x++)
    {
    move_object(clone_object(" "), this_object());
    }
}*/
if(arg) return;
  set_light(1);
  short_desc = "Nulato Hills Stargate";
  long_desc =
"  ~ Entrance to the Mountain Range ~\n\
  Here lies the foothills of the Nulato Hills Mountains.  A huge\n\
forest surrounds everything as the path continues through the\n\
hills to the mountains as far as the eyes can see.  Small animals\n\
scurry into the forest as you hurry through the path and becomes\n\
silent as if some great presence lurks within.\n";

  items =
  ({
    "",
    "",
  });
  dest_dir =
  ({
  });
}