/*                                                                    *
 *    File:             /players/angel/area/atlantis/room/ag.c        *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2007 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           12/15/07                                      *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if( !present("teyla", this_object()) )
    move_object(clone_object("/players/angel/area/atlantis/npc/teyla.c"), this_object());
  if( !present("ronon", this_object()) )
    move_object(clone_object("/players/angel/area/atlantis/npc/ronon.c"), this_object());
if(arg) return;
  set_light(1);
  short_desc = "Atlantis GYM";
  long_desc =
"    "+WHT+"~ GYM ~"+NORM+"\n\
"+HIB+"  Whether designated by the Ancients or the Atlantis expedition,\n\
a gym has been laid aside for cardiovascular activity. Here, Teyla\n\
Emmagan regularly trains with John Sheppard, or other Athosians who\n\
have come in from the mainland for practice with their leader. This\n\
room is a large open area with mats covering the floor and hand\n\
weapons covering the walls."+NORM+"\n";

  items =
  ({
    "mats",
    "A large blue four inch thick foam mat, it looks soft",
    "weapons",
    "Many different types of woden hand instruments",
    "floor",
    "covered with blue mats",
    "wall",
    "covered with hand weapons for training",
    "walls",
    "covered with hand weapons for training",
  });

  dest_dir =
  ({
	"/players/angel/area/atlantis/room/hall_10.c",     "east",
  });
}