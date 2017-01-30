/*                                                                    *
 *    File:             /players/angel/area/atlantis/room/cm.c        *
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
    for(x=0; x<3; x++)
    {
    move_object(clone_object("/players/angel/area/stargate/npc/private_02.c"), this_object());
    }
}
if(arg) return;
  set_light(1);
  short_desc = "CHAIR ROOM";
  long_desc =
"      "+WHT+"~ CHAIR ROOM ~"+NORM+"\n\
"+HIB+"    Like Atlantis Outpost in Antarctica a powerful chair-weapons\n\
platform is provided for defense of the city. The chair directly\n\
connects to Atlantis's three drone weapon portals on the city piers.\n\
The chair can also be reconfigured to remotely control Puddle Jumpers\n\
to attack incoming threats."+NORM+"\n";

  items =
  ({
    "chair",
    "made of what looks like a grey metal with many buttons",
    "portals",
    "a means to move objects from one location to another",
    "piers",
    "a large platform",
  });

  dest_dir =
  ({
	"/players/angel/area/atlantis/room/hall_16.c",     "west",
  });
}