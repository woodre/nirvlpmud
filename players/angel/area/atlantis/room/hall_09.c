/*                                                                    *
 *    File:             /players/angel/area/atlantis/room/hall_09.c   *
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
  short_desc = "Hall";
  long_desc =
"    "+WHT+"~ Hall ~"+NORM+"\n\
"+HIB+"  Along these halls in this massive complex there is high tech\n\
equipment.  Anyone looking around would feel inept trying to\n\
figure out what all the screens are used for. Halls lead to many\n\
different areas of Atlantis. The lighting and all room functions\n\
turn on and off as people walk in and out of each area."+NORM+"\n";

  items =
  ({
    "equipment",
    "computerized panels with an unknown language",
    "screens",
    "computerized flat panels",
    "screen",
    "computerized flat panel",
    "lights",
    "The area is lit up but no noticeable fixtures",
    "lighting",
    "The area is lit up but no noticeable fixtures",
  });

  dest_dir =
  ({
	"/players/angel/area/atlantis/room/t.c",           "north",
    "/players/angel/area/atlantis/room/hall_08.c",     "southwest",
  });
}