/*                                                                    *
 *    File:             /players/angel/area/atlantis/room/oc.c        *
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
  if( !present("sergeant", this_object()) )
  { 
    for(x=0; x<2; x++)
    {
    move_object(clone_object("/players/angel/area/stargate/npc/sergeant.c"), this_object());
    }
}
if(arg) return;
  set_light(1);
  short_desc = "OPERATIONS CENTER";
  long_desc =
"      "+WHT+"~ Operations Center ~"+NORM+"\n\
"+HIB+"  Positioned across and above the Stargate area, the operations\n\
area is the control center of the entire Atlantis base. It is\n\
equipped with numerous control stations that allow for the\n\
monitoring and maintaining of the base.  From here personnel\n\
can also control the Stargate forcefield, consult the city's\n\
database of gate addresses, manage the city's power resources\n\
and city-wide communications systems, and more."+NORM+"\n";

  items =
  ({
	"database",
	"you are not authorized  to access computers",
	"systems",
	"you are not authorized to access computers",
    "center",
    "this is the base of operations",
    "stations",
    "a place where military personnel work",
    "station",
    "a place where military personnel work",
  });

  dest_dir =
  ({
	"/players/angel/area/atlantis/room/cr.c",       "command",
	"/players/angel/area/atlantis/room/s_02.c",     "southwest",
	"/players/angel/area/atlantis/room/hall.c",     "east",
    "/players/angel/area/atlantis/room/s_04.c",     "west",
    
  });
}