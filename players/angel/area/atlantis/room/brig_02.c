/*                                                                    *
 *    File:             /players/angel/area/atlantis/room/brig_02.c   *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2007 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           06/25/08                                      *
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
  if( !present("wraith", this_object()) )
    move_object(clone_object("/players/angel/area/atlantis/npc/wraith.c"), this_object());
if(arg) return;
  set_light(1);
  short_desc = "LIVING QUARTERS";
  long_desc =
"      "+WHT+"~ Inside of Brig ~"+NORM+"\n\
"+HIB+"  This is the inside of the Atlantis brig. This chamber\n\
is bare. The walls looks to be gray metal mesh on all\n\
four sides."+NORM+"\n";

  items =
  ({
	"forcefield",
	"made of high tech lasers and can be disarmed with the right knowledge",
	"chamber",
    "gray metal mesh walls reinforced with a laser forcefield\n\
    and there is a small box by the entrance",
    "walls",
    "The walls appear to be a solid titanium allow",
    "wall",
    "The walls appear to be a solid titanium allow",
    "metal",
    "it is solid titanium allow",
    "mesh",
    "It has many large holes in the wall but the forcefield\n\
    prevents anything from going through",
  });

  dest_dir =
  ({
	"/players/angel/area/atlantis/room/brig.c",     "south",
  });
}