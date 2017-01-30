/*                                                                    *
 *    File:             /players/angel/area/atlantis/room/mh_02.c     *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2007 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           08/15/07                                      *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "room/room";
int x;

reset(arg)
{
  ::reset(arg);
  if( !present("corporal", this_object()) )
  {
    for(x=0; x<3; x++)
    {
    move_object(clone_object("/players/angel/area/stargate/npc/corporal.c"), this_object());
    }
}
if(arg) return;
  set_light(1);
  short_desc = "MESS HALL";
  long_desc =
"    "+WHT+"~ SECOND LEVEL MESS HALL ~"+NORM+"\n\
"+HIB+"  Overlooking a pier of the city lies the mess hall, where Atlantis\n\
expedition members and their guests can take in a view of the city\n\
while eating a meal brought in from the Daedalus (locally in the\n\
Pegasus Galaxy).  In the event of a chilly day, a retractable glass\n\
wall will close in the room."+NORM+"\n";

  items =
  ({
   "pier",
    "a large open platform",
    "hall",
    "a large open room with tables and chairs",
    "wall",
    "a massively large piece of unbreakable glass",
  });

  dest_dir =
  ({
	"/players/angel/area/atlantis/room/hall_12.c",     "east",
  });
}