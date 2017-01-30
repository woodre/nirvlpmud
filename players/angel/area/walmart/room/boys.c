/*                                                                              *
 *      File:             /players/angel/area/walmart/room/boys.c               *
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
  if( !present("mannequin", this_object()) )
  {
    for(x=0; x<2; x++)
    {
    move_object(clone_object("/players/angel/area/walmart/npc/manakin.c"), this_object());
    }
}
if(arg) return;
  set_light(1);
  short_desc = HIR+"Boys Department"+NORM;
  long_desc =
"  "+HIR+"Boys Department"+NORM+"\n\
Look cool at school, get him the clothes he wants and needs\n\
for everyday. We carry Rugged and stylish, outerwear that is\n\
just the stuff for boys who like to get out and play. We also\n\
carry Classic looks that fit most any school dress code.\n";

  items =
  ({
    "school",
    "A place where children got to recieve an education",
    "clothes",
    "There are several different items made of fabric and/or material\n\
formed by weaving, knitting, pressing, or felting natural or\n\
synthetic fibers",
    "outerwear",
    "Clothing, such as hats, coats, and gloves, for use outdoors",
    "boys",
    "A human male child",
    
    
  });
  dest_dir =
  ({
    "/players/angel/area/walmart/room/softlines",  "softlines",
  });
}
realm(){ return "NT"; }
