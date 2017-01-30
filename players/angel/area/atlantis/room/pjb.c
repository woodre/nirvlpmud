/*                                                                    *
 *    File:             /players/angel/area/atlantis/room/pjb.c       *
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
  if( !present("corporal", this_object()) )
  { 
    for(x=0; x<3; x++)
    {
    move_object(clone_object("/players/angel/area/stargate/npc/corporal.c"), this_object());
    }
}  
if(arg) return;
  set_light(1);
  short_desc = "PUDDLE JUMPER BAY";
  long_desc =
"    "+WHT+"~ PUDDLE JUMPER BAY ~"+NORM+"\n\
"+HIB+"  Atlantis is equipped with a spacious, circular Puddle Jumper bay,\n\
filled with multiple decks of the small crafts. This room is located\n\
directly above the gate room. After selecting a Jumper, the pilot\n\
moves the ship into the center of the room, where the panels on the\n\
floor retract, so that the ship may be piloted through the Stargate.\n\
retract into the surrounding walls to allow entrance into the gate\n\
controls can also retract the roof of the Jumper bay, allowing the\n\
ships access to the outside of the city."+NORM+"\n";

  items =
  ({
    "bay",
    "a large open area to store ships",
    "jumper",
    "a small ship that can go through the gate",
    "crafts",
    "a small ship that can go through the gate",
    "ship",
    "a small jumper that can go through the gate",
    "roof",
    "it looks retractable",
    "floor",
    "it looks retractable",
    "decks",
    "a platform to connect with the jumpers",
    "deck",
    "a platform to connect with the jumpers",
  });

  dest_dir =
  ({
	"/players/angel/area/atlantis/room/tp_05.c",     "west",
	"/players/angel/area/atlantis/room/ds.c",        "up",
  });
}