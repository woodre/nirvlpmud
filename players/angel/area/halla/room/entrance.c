/*                                                                    *
 *    File:             /players/angel/area/asgard/room/entrance.c    *
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
  short_desc = "Asgard Stargate";
  long_desc =
"  ~ Asgard Homeworld ~\n\
  This ia a large open room. To the south is the stargate and to\n\
the north there is a long hall in the shape of an asgard head. The\n\
walls seem to made of a solid grey metal.\n";

  items =
  ({
    " ",
    " ",
  });
  dest_dir =
  ({
  });
}