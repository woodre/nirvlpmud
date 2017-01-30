/*                                                                    *
 *    File:             /players/angel/area/stargate/room/ir.c        *
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
  short_desc = HIC+"Infirmary"+NORM;
  long_desc =
"    "+HIC+"~ Infirmary ~"+NORM+"\n\
"+CYN+"  Whether electrocuted by the base's power grid struck by\n\
anerrant staff blast, the infirmary is equipped to handle most\n\
needs relating to gate travel. It is even able to care for\n\
Goa'uld symbiotes. Several Chief Medical Officers are stationed\n\
on base."+NORM+"\n";

  items =
  ({
	"base",
	"A large underground falicity that shelters military equipment and personnel",
	"symbiotes",
	"A worm like parasite",
	"gate",
	"The Stargate transfers a person or object into energy as it\n\
     passes through the event horizon, then transmits it through\n\
     the wormhole to the receiving stargate which then reconstructs\n\
     the matter in its original form",
  });

  dest_dir =
  ({
	"/players/angel/area/stargate/room/hall2", "west",
  });
}

init(){
  ::init();
    this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }

realm(){ return "NT"; }