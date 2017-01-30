/*                                                                    *
 *    File:             /players/angel/area/stargate/room/iw.c         *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2006 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           11/15/06                                      *
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
  if(arg) return;
  set_light(1);
  short_desc = HIC+"ISOLATION WARD"+NORM;
  long_desc =
"    "+HIC+"~ ISOLATION WARD ~"+NORM+"\n\
"+CYN+"  Stargate travel is at worst risky, and at best uncertain. At least\n\
one configurable isolation ward is available on S.G.C. levels, though\n\
there are likely more. An observation lounge directly opposite the\n\
ward can hold several people to monitor the patients. High voltage can\n\
be routed through the outside corridor and into equipment in the room\n\
if the occupant is particularly dangerous."+NORM+"\n";

  items =
  ({
	"equipment",
	"useful tools",
	"ward",
	"hospital area for a critical group of patients",
  });

  dest_dir =
  ({
	"/players/angel/area/stargate/room/hall8", "east",
  });
}

init(){
  ::init();
    this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }

realm(){ return "NT"; }