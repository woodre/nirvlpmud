inherit "room/room";
/*                                                                    *
 *    File:             /players/angel/area/atlantis/room/entrance.c  *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2007 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           06/15/07                                      *
 *    Notes:            Entrance                                      *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"

#include <ansi.h>

#include "/players/angel/area/stargate/obj/dial_obj.c"


int x;

reset(arg)
{
  ::reset(arg);
  /* the computer displays where players can travel */
  if(!present("dhd"))
     move_object(clone_object("/players/angel/area/stargate/obj/dhd"), this_object());
  if( !present("sergeant", this_object()) )
  {
    for(x=0; x<4; x++)
    {
    move_object(clone_object("/players/angel/area/stargate/npc/sergeant.c"), this_object());
    }
}
if(arg) return;
  set_light(1);
  short_desc = "Atlantis Gate Room";
  long_desc =
"      "+WHT+"~ GATE ROOM ~"+NORM+"\n\
"+HIB+"    This is the Atlantis gate room.  The gate room is massive, and\n\
suited for battalions of departing soldiers or enormous expeditions.\n\
A platform in the center holds the Stargate, allowing access from\n\
many different sides in the event of a medical emergency or abrupt\n\
evacuation by personnel. Stairs lead downward on either side of the\n\
gate, and an upward staircase directly in front of the gate leads\n\
up to the operations and conference rooms. Small terraces overlook\n\
the gate room on either side of the second level, and the ceiling\n\
retracts to allow access to and from the Puddle Jumper bay allowing\n\
the team to take the small Ancient ships through the Stargate."+NORM+"\n";

  items =
  ({
    "platform",
    "A large juncture built to connect the stargate to the rest of the room",
    "stargate",
    "The Stargate transfers a person or object into energy as it\n\
     passes through the event horizon, then transmits it through\n\
     the wormhole to the receiving stargate which then reconstructs\n\
     the matter in its original form",
    "gate",
    "The Stargate transfers a person or object into energy as it\n\
     passes through the event horizon, then transmits it through\n\
     the wormhole to the receiving stargate which then reconstructs\n\
     the matter in its original form",
    "stairs",
    "words written in Ancient illuminate the stairs",
    "staircase",
    "words written in Ancient illuminate the stairs",
    "terrace",
    "it is like a second level porch with metal rails",
    "ceiling",
    "very high open area",
    "dhd",
    "You should try to 'view dhd'",
    "DHD",
    "You should try to 'view dhd'",
  });

  dest_dir =
  ({
    "/players/angel/area/atlantis/room/s_01.c",     "north",
    "/players/angel/area/atlantis/room/s_03.c",     "east",
  });
}
