/*                                                                    *
 *    File:             /players/angel/area/atlantis/room/ds.c        *
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
  if( !present("private", this_object()) )
  { 
    for(x=0; x<2; x++)
    {
    move_object(clone_object("/players/angel/area/stargate/npc/private_02.c"), this_object());
    }
}
if(arg) return;
  set_light(1);
  short_desc = "DRONE STORAGE";
  long_desc =
"    "+WHT+"~ DRONE STORAGE BAY ~"+NORM+"\n\
"+HIB+"  The drone storage bay houses an enormous supply, if not all, of\n\
Ancient drone weapons. The devices remain on stand-by in honeycomb\n\
like racks until they are required to launch.  This bay is likely\n\
configured for automatic launching of the weapons, routing the\n\
drones to three portals on three separate piers where they can\n\
emerge and attack."+NORM+"\n";

  items =
  ({
    "weapons",
    "like noting you have ever seen",
    "drone",
    "a flying weapon",
    "racks",
    "large metal shelves storing drones",
    "portals",
    "a means to move objects from one location to another",
    "piers",
    "a large platform",
  });

  dest_dir =
  ({
	"/players/angel/area/atlantis/room/pjb.c",     "down",
  });
}