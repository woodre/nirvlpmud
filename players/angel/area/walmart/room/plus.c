/*                                                                              *
 *      File:             /players/angel/area/walmart/room/plus.c               *
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
  short_desc = HIR+"Plus sizes"+NORM;
  long_desc =
"  "+HIR+"Plus sizes"+NORM+"\n\
Welcome to the women's plus size clothing department. We are\n\
the fashion leader in women's plus-size clothing, sizes 14-28.\n\
We have the sexiest intimate apparel for curvy women and we\n\
provide fashion forward styles for plus size jrs and women.\n\
Shop around and let us know what you think!\n";

  items =
  ({
    "departments",
    "This is different areas of the store that sell merchandise\n\
that is unique to that area!",
    "leader",
    "An active company that tends to lead the general market in sales",
    "clothing",
    " Fabric or material formed by weaving, knitting, pressing,\n\
or felting natural or synthetic fibers",
    "apparel",
    "Clothing, especially outer garments or attire",
    "women",
    "An adult female human",
    "jrs",
    "An adolescent female human",

  });
  dest_dir =
  ({
   	"/players/angel/area/walmart/room/softlines", "softlines",
  });
}
realm(){ return "NT"; }
