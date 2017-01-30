/*                                                                    *
 *    File:             /players/angel/area/stargate/room/dl.c        *
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
  if( !present("jackson", this_object()) )
    move_object(clone_object("/players/angel/area/stargate/npc/jackson.c"), this_object());
  if(arg) return;
  set_light(1);
  short_desc = HIC+"Daniel's Lab"+NORM;
  long_desc =
"    "+HIC+"~ Daniel's Lab ~"+NORM+"\n\
"+CYN+"  This lab contains artifacts spanning centuries, Daniel maintains his\n\
reference materials on alien cultures and interfaces with the base's\n\
computer archive from this lab. His translations of Ancient and Unas\n\
languages, as well as his examination of materials recovered through\n\
the Stargate occurs in this room."+NORM+"\n";

  items =
  ({
	"lab",
	"There are a lots of odd objects in the room",
	"base",
	"A large underground falicity that shelters military equipment and personnel",
	"computer",
	"An electronic tool",
	"archive",
	"A large database",
	"materials",
	"alien artifacts",
	"stargate",
	"The Stargate transfers a person or object into energy as it\n\
     passes through the event horizon, then transmits it through\n\
     the wormhole to the receiving stargate which then reconstructs\n\
     the matter in its original form",
  });

  dest_dir =
  ({
	"/players/angel/area/stargate/room/hall12", "east",
  });
}

init(){
  ::init();
    this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }

realm(){ return "NT"; }