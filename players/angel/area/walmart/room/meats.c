/*                                                                              *
 *      File:             /players/angel/area/walmart/room/meats.c              *
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
  if( !present("hog", this_object()) )
  {
    for(x=0; x<2; x++)
    {
    move_object(clone_object("/players/angel/area/walmart/npc/pork.c"), this_object());
    }
}
if(arg) return;
  set_light(1);
  short_desc = HIY+"Meat department"+NORM;
  long_desc =
"   "+HIY+"Meats"+NORM+"\n\
  The Butcher Shoppe at Wal-Mart offers a full service meat\n\
counter and a friendly, knowledgeable staff who can help you\n\
make the perfect selections for your favorite recipes. Our\n\
promise of offering Quality, Selection and Savings Every Day\n\
holds true in our meat department as well as throughout the\n\
rest of the store. We work hard to consistently provide you\n\
with the high standards of quality and freshness everyone\n\
expect from Wal-Mart.\n";

  items =
  ({
    "shoppe",
    "A small retail store or a specialty department in a large store",
    "walmart",
    "Wal-Mart is a large retailer bent on overtaking the world!",
    "meat",
    "The edible flesh of animals, tasty!",
    "recipe",
    "A list of ingredients for making or preparing something",
    "department",
    "This is different areas of the store that sell merchandise\n\
that is unique to that area!",
    "store",
    "A place where merchandise is offered for sale",

  });
  dest_dir =
  ({
    "/players/angel/area/walmart/room/foods", "foods",	
  });
}
realm(){ return "NT"; }