/*                                                                              *
 *      File:             /players/angel/area/walmart/room/produce.c            *
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
  if( !present("orange", this_object()) )
  {
    for(x=0; x<2; x++)
    {
    move_object(clone_object("/players/angel/area/walmart/npc/orange.c"), this_object());
    }
}
if(arg) return;
  set_light(1);
  short_desc = HIY+"Produce Isle"+NORM;
  long_desc =
"   "+HIY+"Produce"+NORM+"\n\
  Juicy, ripe tomatoes, mouth-watering nectarine's, tongue-tingling\n\
peppers what do these foods all have in common?  They're just a few\n\
of the remarkably delicious choices you'll find in the Produce\n\
Department at Wal-Mart! Our abundant selection of only the freshest\n\
fruits and vegetables include everything from ready-to-eat salads\n\
and freshly-cut fruit to certified organics and locally grown items.\n\
Shop at Wal-Mart and discover the quality and freshness our customers\n\
deserve at Everyday Low Prices that anyone would have to see to believe.\n\
We offer the best of the best, each and every day!\n";

  items =
  ({
    "tomatoes",
    "A cultivated South American plant having edible, fleshy, usually red fruit.",
    "nectarine",
    "A variety of aromatic peach of ancient origin, having a smooth, waxy skin",
    "peppers",
    "The pod-like fruit of any of these plants, varying in size and shape",
    "food",
    "Nourishment eaten in solid form",
    "produce",
    "Farm products, especially fresh fruits and vegetables",
    "produce department",
    "A department in the store that sales produce",
    "department",
    "This is different areas of the store that sell merchandise\n\
that is unique to that area!",
    "walmart",
    "Wal-Mart is a large retailer bent on overtaking the world!",
    "fruits",
    "An edible, usually sweet and fleshy form of plant product",
    "vegetables",
    "A plant cultivated for consumption",
    "salads",
    "A dish of raw leafy green vegetables",
    "family",
    "Families are people who share goals and values, have long-term\n\
commitments to one another, and reside usually in the same dwelling\n\
place",

  });
  dest_dir =
  ({
     "/players/angel/area/walmart/room/foods", "foods",	
  });
}
realm(){ return "NT"; }
