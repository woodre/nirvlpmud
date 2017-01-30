/*                                                                    *
 *    File:             /players/angel/area/atlantis/room/            *
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

reset(arg)
{
  ::reset(arg);
  if( !present("mckay", this_object()) )
    move_object(clone_object("/players/angel/area/atlantis/npc/mckay.c"), this_object());
if(arg) return;
  set_light(1);
  short_desc = "Atlantis laboratories";
  long_desc =
"    "+WHT+"~ laboratory ~"+NORM+"\n\
"+HIB+"  There are multiple scientific laboratories in Atlantis. This\n\
facility is in the command tower. Dr. Mckay uses this lab.\n\
This room seems to be the largest room in the city. Since the city\n\
is largely unexplored, and it undoubtedly holds numerous Ancient\n\
technologies just waiting to be studied, this is where items are\n\
brought to for research by the second generation of humankind."+NORM+"\n";

  items =
  ({
    "lab",
    "a large room with many tools",
  });

  dest_dir =
  ({
	"/players/angel/area/atlantis/room/hall_14.c",     "east",
  });
}