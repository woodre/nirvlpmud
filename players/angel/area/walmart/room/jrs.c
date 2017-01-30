/*                                                                              *
 *      File:             /players/angel/area/walmart/room/jrs.c                *
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
  short_desc = HIR+"Jrs department"+NORM;
  long_desc =
"  "+HIR+"Jrs department"+NORM+"\n\
Find the hottest junior apparel here! We carry junior clothing\n\
and teen clothing all at amazing price! We can dress you in the\n\
hottest trendy clothes such as: low rise jeans, junior dresses,\n\
junior tops, skirts and much more.\n";

  items =
  ({
    "departments",
    "This is different areas of the store that sell merchandise\n\
that is unique to that area!",
    "apparel",
    "Clothing, especially outer garments or attire",
    "clothing",
    "Fabric or material formed by weaving, knitting, pressing,\n\
or felting natural or synthetic fibers",
    "jeans",
    "Pants made of denim, a durable fabric",
    "dresses",
    "A one-piece outer garment for women or girls",
    "tops",
    "A garment worn on the upper half of the body",
    "skirts",
    "The part of a garment that hangs freely from the waist down",

  });
  dest_dir =
  ({
    "/players/angel/area/walmart/room/softlines", "softlines",
  });
}
realm(){ return "NT"; }
