/*                                                                    *
 *    File:             /players/angel/area/arachnos/room/entrance.c  *
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
  short_desc = "Arachnos Stargate";
  long_desc =
"  ~ Giant Spider Web ~\n\
  One must Balance carefully on the giant sticky threads that\n\
holds the giant web in place.  A strand leads to the south\n\
towards a cave-like structure made from many layers of a spider\n\
web. Another silky strand continues to the north.  The immense\n\
spider web is moving softly and Danger is around every corner.\n";

  items =
  ({
    " ",
    " ",
  });
  dest_dir =
  ({
    " ", " ",	
  });
}