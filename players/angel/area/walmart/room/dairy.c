/*                                                                              *
 *      File:             /players/angel/area/walmart/room/dairy.c              *
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
  if( !present("padano", this_object()) )
  {
    for(x=0; x<2; x++)
    {
    move_object(clone_object("/players/angel/area/walmart/npc/padano.c"), this_object());
    }
}
if(arg) return;
  set_light(1);
  short_desc = HIY+"Dairy Isle"+NORM;
  long_desc =
"   "+HIY+"Dairy"+NORM+"\n\
  The friendly staff in our full-service Wal-Mart Dairy will\n\
gladly help you make the perfect selection. Our wide variety\n\
of high-quality dairy products such as milk, cheese, yogurt,\n\
butter, biscuits, and much more gives customers many options to\n\
choose from.\n";

  items =
  ({
    "staff",
    "They are a friendly group of workers",
    "walmart",
    "Wal-Mart is a large retailer bent on overtaking the world!",
    "dairy",
    "We sale many products relating to milk",
    "products",
    "Something produced by human or mechanical effort or by a\n\
natural process",
    "milk",
    "A whitish liquid containing proteins, fats, lactose, and\n\
various vitamins and minerals that is produced by cows",
    "cheese",
    "A product of milk",
    "yogurt",
    "A product of milk",
    "butter",
    "A product of milk",
    "biscuits",
    "A small cake of shortened bread",
    
  });
  dest_dir =
  ({
    "/players/angel/area/walmart/room/foods",  "foods",
  });
}
realm(){ return "NT"; }