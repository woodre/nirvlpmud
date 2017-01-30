/*                                                                    *
 *    File:             /players/angel/area/selangor/room/entrance.c  *
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
  short_desc = "Selangor Stargate";
  long_desc =
"    ~ The Entrance to the Daemon Inn ~\n\
  You find yourself in an entrance foyer to the Daemon Inn. Silver\n\
plated stairs spiral up to the reception area. To the south you hear\n\
the sounds of exuberance and drinking while from the west you hear\n\
the bustling activity of Selangor.\n";

  items =
  ({
    " ",
    " ",
  });
  dest_dir =
  ({
  });
}