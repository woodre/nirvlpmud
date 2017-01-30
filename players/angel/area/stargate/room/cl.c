/*                                                                    *
 *    File:             /players/angel/area/stargate/room/cl.c        *
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
  if( !present("carter", this_object()) )
    move_object(clone_object("/players/angel/area/stargate/npc/carter.c"), this_object());
  if(arg) return;
  set_light(1);
  short_desc = HIC+"Carter's Lab"+NORM;
  long_desc =
"    "+HIC+"~ Carter's Lab ~"+NORM+"\n\
"+CYN+"  Though a key member of SG-1, Samantha Carter is a scientist at her\n\
core. She maintains this small lab where she occupies herself during\n\
her off hours from SG-1, helping Stargate Command further its\n\
knowledge of science and technology. "+NORM+"\n";

  items =
  ({
    "member",
    "Team player",
	"scientist",
    "The scientist studies science",
    "lab",
    "There are a lots of odd objects in the room",
    "SG-1",
    "An elite military unit",
    "Stargate Command",
    "Earth's base of operations for off-world surveillance and reconnaissance through the Stargate",
    "stargate command",
    "Earth's base of operations for off-world surveillance and reconnaissance through the Stargate",
    "Stargate",
    "The Stargate transfers a person or object into energy as it\n\
     passes through the event horizon, then transmits it through\n\
     the wormhole to the receiving stargate which then reconstructs\n\
     the matter in its original form",
    "stargate",
    "The Stargate transfers a person or object into energy as it\n\
     passes through the event horizon, then transmits it through\n\
     the wormhole to the receiving stargate which then reconstructs\n\
     the matter in its original form",
    "science",
    "any system of objective knowledge",
    "technology",
    "You get a sense it is dealing with the use and knowledge of humanity's tools",
  });

  dest_dir =
  ({
	"/players/angel/area/stargate/room/hall12", "west",
  });
}

init(){
  ::init();
    this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }

realm(){ return "NT"; }