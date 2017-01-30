/*                                                                              *
 *      File:             /players/angel/area/walmart/room/hardware.c           *
 *      Function:         room                                                  *
 *      Author(s):        Angel@Nirvana                                         *
 *      Copyright:        Copyright (c) 2006 Angel (Josh Hatfield)              *
 *                                All Rights Reserved.                          *
 *      Source:           11/15/06                                              *
 *      Notes:                                                                  *
 *                                                                              *
 *                                                                              *
 *      Change History:                                                         *
 */

#include <ansi.h>

inherit "room/room";

int x;

reset(arg)
{
  ::reset(arg);
  if( !present("polan", this_object()) )
  {
    for(x=0; x<2; x++)
    {
    move_object(clone_object("/players/angel/area/walmart/npc/polan.c"), this_object());
    }
}
if(arg) return;
  set_light(1);
  short_desc = HIB+"Hardware department"+NORM;
  long_desc =
"   "+HIB+"Hardware Department"+NORM+"\n\
  Wal-Mart is the place for a wide variety of Power Tools, Air\n\
Tools, Cordless Tools, Mechanic Tools, and Hand Tools, including\n\
Air Compressors, Circular Saws, Cordless Drills, Sawhorses, Screw\n\
driver Sets, Wrench Sets, Tool Boxes, Chisels, Automotive Air Tools\n\
and Table Saws. Enjoy your purchase!!\n";

  items =
  ({
    "tool",
    "A device, such as a saw, used to perform or facilitate manual or mechanical work",
    "tools",
    "A device, such as a saw, used to perform or facilitate manual or mechanical work",
    "air compressors",
    "A machine that increases the pressure of a gas or air in a tank for later use",
    "sawhorses",
    "A frame with legs, used to support pieces of wood being sawed",
    "sets",
    "A grouping of objects",
    "boxes",
    "A container typically constructed with four sides perpendicular\n\
to the base and having a lid or cover",
    "chisels",
    "A metal tool with a sharp beveled edge, used to cut and shape stone, wood, or metal",
    "table saw",
    "A tabletop that is made cast iron with a saw blade mounted\n\
in the middle for cutting materials",

  });
  dest_dir =
  ({
   "/players/angel/area/walmart/room/hardlines", "hardlines",
  });
}
realm(){ return "NT"; }