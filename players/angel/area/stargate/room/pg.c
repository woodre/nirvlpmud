/*                                                                    *
 *    File:             /players/angel/area/stargate/room/pg.c        *
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
  short_desc = HIC+""+NORM;
  long_desc =
"    "+HIC+"~ Power Grid ~"+NORM+"\n\
"+CYN+"  This system regulates power for various systems throughout the\n\
S.G.C., but particularly relating to the Stargate. A code must\n\
be entered to pass through the security fence and access the grid.\n\
If the Stargate's power systems are fluctuating, feedback is not\n\
an uncommon occurrence."+NORM+"\n";

  items =
  ({
	"stargate",
	"The Stargate transfers a person or object into energy as it\n\
     passes through the event horizon, then transmits it through\n\
     the wormhole to the receiving Stargate which then reconstructs\n\
     the matter in its original form",
	"fence",
	"a metal chain link fence",
	"grid",
	"stargate's power system",
  });

  dest_dir =
  ({
	"/players/angel/area/stargate/room/hall13", "west",
  });
}

init(){
  ::init();
    this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }

realm(){ return "NT"; }