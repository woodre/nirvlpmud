/*                                                                    *
 *    File:             /players/angel/area/acheron/room/entrance.c   *
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
  short_desc = " ";
  long_desc =
"    ~ A muddy road ~\n\
  Along the road are rocks scattered between all the mud.\n\
The sky is full of thick clouds, the sun appears as a dull\n\
glob, and the wind howls through out the hills messing up\n\
your hair.  There are three large planet like objects in\n\
the sky, each a different color.  The grey stone pinnacles\n\
jutting out of the ground have been carved into strange\n\
unknown shapes.  All around are low barren hills.\n";

  items =
  ({
    " ",
    " ",
  });
  dest_dir =
  ({
  });
}