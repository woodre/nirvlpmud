/*                                                                              *
 *      File:             /players/angel/area/walmart/room/deli.c               *
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
  if( !present("chicken", this_object()) )
  {
    for(x=0; x<2; x++)
    {
    move_object(clone_object("/players/angel/area/walmart/npc/chicken.c"), this_object());
    }
}
if(arg) return;
  set_light(1);
  short_desc = HIY+"Deli Isle"+NORM;
  long_desc =
"   "+HIY+"Deli"+NORM+"\n\
  The friendly staff in our full-service Wal-Mart Deli will\n\
gladly help you make the perfect selection. Our wide variety\n\
of high-quality meats and cheeses from both local and national\n\
brands are freshly sliced to order to the customers exact\n\
specifications. Ask one of our helpful Deli Associates for a\n\
sample of any product to try and enjoy the great taste.\n";

  items =
  ({
    "staff",
    "They are a group of workers",
    "walmart",
    "Wal-Mart is a large retailer bent on overtaking the world!",
    "deli",
    "A shop that sells cooked or prepared foods ready for serving",
    "meat",
    "The edible flesh of animals, tasty!",
    "cheese",
    "A product of milk",
    "local",
    "Relating to a city, town, or district rather than a larger area",
    "national",
    "Relates to a large area, something that is sold across the whole\n\
nation. A large area under one rule",
    "associates",
    "People who work for the company that joined as a partner",
    "sample",
    "to test or taste by a sample",
    "product",
    "Something produced by human or mechanical effort or by a\n\
natural process",

  });
  dest_dir =
  ({
    "/players/angel/area/walmart/room/foods",  "foods",
  });
}
realm(){ return "NT"; }