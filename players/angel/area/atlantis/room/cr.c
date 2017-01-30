/*                                                                    *
 *    File:             /players/angel/area/atlantis/room/cr.c        *
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
  if( !present("weir", this_object()) )
    move_object(clone_object("/players/angel/area/atlantis/npc/weir.c"), this_object());
  if( !present("sheppard", this_object()) )
    move_object(clone_object("/players/angel/area/atlantis/npc/sheppard.c"), this_object());
if(arg) return;
  set_light(1);
  short_desc = "CONFERENCE ROOM";
  long_desc =
"    "+WHT+"~ CONFERENCE ROOM ~"+NORM+"\n\
"+HIB+"    A basic space with a large table, where the team conducts mission\n\
briefings and other meetings. The conference room is directly across\n\
the gateroom from the operations center.  A series of multi-panel\n\
doors open onto a terrace overlooking the Stargate."+NORM+"\n";

  items =
  ({
    "table",
    "A large glass top conference table",
    "gateroom",
    "A large open room where the stargate sits",
    "doors",
    "Automatic full length glass panels",
    "terrace",
    "it is a second level porch with metal rails overlooking the stargate",
    "stargate",
    "The Stargate transfers a person or object into energy as it\n\
     passes through the event horizon, then transmits it through\n\
     the wormhole to the receiving stargate which then reconstructs\n\
     the matter in its original form",
  });

  dest_dir =
  ({
	"/players/angel/area/atlantis/room/oc.c",     "out",
  });
}