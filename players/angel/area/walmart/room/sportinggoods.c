/*                                                                              *
 *      File:             /players/angel/area/walmart/roomsportinggoods/.c      *
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
  if( !present("mossberg", this_object()) )
  {
    for(x=0; x<2; x++)
    {
    move_object(clone_object("/players/angel/area/walmart/npc/mossberg.c"), this_object());
    }
}
if(arg) return;
  set_light(1);
  short_desc = HIB+"Sporting goods"+NORM;
  long_desc =
"   "+HIB+"Sporting goods Department"+NORM+"\n\
  Wal-Mart's Sporting Goods is one of America's top retailers of\n\
name brand sporting goods and accessories. With over 2000 locations\n\
spread throughout United States you can find a convenient store\n\
location near you. We provide a full-line of products offered in any\n\
traditional sporting goods store. Our product mix includes a broad\n\
selection of outdoor and athletic equipment for team sports, fitness,\n\
camping, hunting, fishing, tennis, golf, snow boarding and in-line\n\
skating. Enjoy shopping!\n";

  items =
  ({
    "retailer",
    "A merchant who sells goods at retail prices",
    "accessories",
    "Something nonessential but desirable that contributes to an\n\
effect or result",
    "product",
    "Something produced by human or mechanical effort or by a\n\
natural process",
    "equipment",
    "Implements used in an operation",
    "team",
    "A group of people on the same side",
    "sports",
    "Physical activity that is governed by a set of rules",
    "camping",
    "A place where tents, hut's, or other temporary shelters are set up",
    "hunting",
    "To pursue game for food or sport",
    "fishing",
    "To pursue fish for food or sport",
    "tennis",
    "A game played with rackets and a light ball by two players",
    "golf",
    "A game played on a large outdoor course with a series of 9 or 18 holes ",
    "skating",
    "To glide or move along on skates",
    "snow boarding",
    "To glide or move along on a snow board",

  });
  dest_dir =
  ({
   "/players/angel/area/walmart/room/hardlines", "hardlines",
  });
}
realm(){ return "NT"; }