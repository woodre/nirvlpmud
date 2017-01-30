/*                                                                    *
 *    File:             /players/angel/area/stargate/room/ctr.c       *
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

void reset(int arg){
  if(arg) return;
  if( !present("mp", this_object()) )
    call_out("get_mp", 1);
  ::reset(arg);
  set_light(1);
  short_desc = HIC+"CONTROL ROOM"+NORM;
  long_desc =
"    "+HIC+"~ CONTROL ROOM  ~"+NORM+"\n\
"+CYN+"  This is the control room. The control room monitors all gate activity,\n\
from outgoing and incoming wormholes to a wide variety of detectable\n\
energy levels surrounding the device's function. Gate technicians,\n\
with duties both to monitor and control the dialing, are on watch 24\n\
hours a day, in the event an off-world team must make an unscheduled\n\
return."+NORM+"\n";

  items =
  ({
	"gate",
	"The Stargate transfers a person or object into energy as it\n\
     passes through the event horizon, then transmits it through\n\
     the wormhole to the receiving stargate which then reconstructs\n\
     the matter in its original form",
	"wormholes",
	"Wormholes traverse vast distances across the galaxy, and even\n\
     between galaxies. The conduit does not always exist, but is\n\
     formed only between two active stargates. An object can travel\n\
     in only one direction in a wormhole, through the initiating gate",
	"device",
	"A tool to transport people",
	"technicians",
	"They are military personal who keep the stargate operating",
	"team",
	"A group of four or five military personal",
  });

  dest_dir =
  ({
	"/players/angel/area/stargate/room/hall6", "north",
  });
}

void get_mp(){
  move_object(clone_object("/players/angel/area/stargate/npc/private_02.c"), this_object());
  tell_room(this_object(), "An MP arrives.\n");
}

init(){
  ::init();
    this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }

realm(){ return "NT"; }