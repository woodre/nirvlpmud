/*                                                                    *
 *    File:             /players/angel/area/gehenna/room/entrance.c   *
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
  set_light(0);
  short_desc = "Gehenna Stargate";
  long_desc =
"  ~ Stone Archway ~\n\
  This is a ancient stone archway.  Various faces of demons and\n\
other forbidding pictures are painted all over this area.  Stone\n\
gargoyles and demons glare down at you from above the arch.  There\n\
is a bronze plaque above the archway.\n";

  items =
  ({
    "archway",
    " ",
    "demons",
    "",
    "pictures",
    "",
    "gargoyles",
    "",
    "arch",
    "",
    "plaque",
    "read plaque",
  });
  dest_dir =
  ({
  });
}