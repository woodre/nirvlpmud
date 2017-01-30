/*                                                                    *
 *    File:             /players/angel/area/stargate/room/lr.c        *
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
  if( !present("vala", this_object()) )
    move_object(clone_object("/players/angel/area/stargate/npc/vala.c"), this_object());
  if(arg) return;
  set_light(1);
  short_desc = HIC+"Lockers"+NORM;
  long_desc =
"    "+HIC+"~ Lockers ~"+NORM+"\n\
"+CYN+"  All Stargate personnel are provided locker rooms for pre and post\n\
missions, and to store civilian items. The Stargate Command has\n\
showers that are here in the locker room which are shared by both\n\
men and women, though on rotating schedules."+NORM+"\n";

  items =
  ({
    "stargate",
	"The Stargate transfers a person or object into energy as it\n\
     passes through the event horizon, then transmits it through\n\
     the wormhole to the receiving Stargate which then reconstructs\n\
     the matter in its original form",
	"items",
	"many personal affects",
	"lockers",
	"metal spaces to hold personal affects",
	"room",
	"This is a large open area",  
  });

  dest_dir =
  ({
	"/players/angel/area/stargate/room/hall11", "west",
  });
}

init(){
  ::init();
    this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }

realm(){ return "NT"; }