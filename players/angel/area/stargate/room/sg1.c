inherit "room/room";
/*                                                                    *
 *    File:             /players/angel/area/stargate/room/sg1.c       *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2006 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           12/23/06                                      *
 *    Notes:            portal to all of Angel's areas                *
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
  if(!present("computer"))
     move_object(clone_object("/players/angel/area/stargate/obj/computer"), this_object());
  if( !present("sergeant", this_object()) )
  {
    for(x=0; x<2; x++)
    {
    move_object(clone_object("/players/angel/area/stargate/npc/sergeant.c"), this_object());
    }
}
  if(arg) return;
  set_light(1);
  short_desc = HIC+"STARGATE /-\\"+NORM;
  long_desc =
"    "+HIC+"~ GATE ROOM ~"+NORM+"\n\
"+CYN+"  This is the newly remolded gate room where the SG teams and others\n\
embark on journeys to other worlds.  A set of rings and a computer\n\
terminal have been added to the room for quicker transportation. The\n\
hub of all Stargate activity on planet Earth, the Gate Room is a\n\
square chamber at the base of the missile silo that runs the entire\n\
course of the mountain. Blast doors occupy opposing sides of the\n\
chamber."+NORM+"\n";

items =
  ({
    "computer",
    "The computer is turned on. Maybe you should try to 'read' the 'screen'",
    "computer terminal",
    "The computer is turned on. Maybe you should try to 'read' the 'screen'",
    "terminal",
    "The computer is turned on. Maybe you should try to 'read' the 'screen'",
    "rings",
    "The rings can transport people back to the surface by dialing the 'rings'",
    "stargate",
    "The Stargate transfers a person or object into energy as it\n\
     passes through the event horizon, then transmits it through\n\
     the wormhole to the receiving stargate which then reconstructs\n\
     the matter in its original form",
    "wormhole",
    "Wormholes traverse vast distances across the galaxy, and even\n\
     between galaxies. The conduit does not always exist, but is\n\
     formed only between two active stargates. An object can travel\n\
     in only one direction in a wormhole, through the initiating gate",
    "teams",
    "A group of four or five military personal",
    "silo",
    "An underground vertical cylindrical container for the storage\n\
     and launching of intercontinental ballistic missiles",
    "mountain",
    "A beautiful landform that extends above the surrounding terrain",
    "gate",
    "The Stargate transfers a person or object into energy as it\n\
     passes through the event horizon, then transmits it through\n\
     the wormhole to the receiving stargate which then reconstructs\n\
     the matter in its original form",
    "room",
    "a large concrete area",
    "chamber",
    "a large concrete area",
    "missile",
    "a large bomb",
    "earth",
    "The planet you live on",
    "doors",
    "They appear to be heavy duty alloy titanium",
  });
  dest_dir =
  ({
    "/room/lanceroad3",                        "rings",
    "/players/angel/area/stargate/room/hall6", "northeast",
  });
}
