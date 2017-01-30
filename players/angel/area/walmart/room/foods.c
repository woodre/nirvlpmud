/*                                                                              *
 *      File:             /players/angel/area/walmart/room/foods.c              *
 *      Function:         room                                                  *
 *      Author(s):        Angel@Nirvana                                         *
 *      Copyright:        Copyright (c) 2006 Angel                              *
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
  if(arg) return;
  set_light(1);
  short_desc = HIY+"Foods"+NORM;
  long_desc =
"   "+HIY+"FOODS"+NORM+"\n\
  Ssssurprise your family for supper! Purchase food at the deli\n\
and you can pay at the checkouts. Our food is packed with care\n\
to ensure quality and freshness. It's packed in a sturdy, reusable,\n\
insulated container and packed with dry ice when needed. Our beef\n\
is cut from the finest corn-fed Midwestern beef. You may browse all\n\
of the different departments but, "+HIR+"BEWARE"+NORM+" of the "+HIM+"strange happenings!"+NORM+"\n\
There is a flier hanging on the wall that you can 'look' at!\n";

  items =
  ({
    "family",
    "Families are people who share goals and values, have long-term\n\
commitments to one another, and reside usually in the same dwelling\n\
place",
    "supper",
    "A light meal eaten before going to bed.",
    "food",
    "Something that nourishes or sustains our physical bodies",
    "deli",
    "A shop that sells cooked or prepared foods ready for serving",
    "checkouts",
    "A counter, usually at the front of a store next to the doors,\n\
where a customers can purchase what the store sells",
    "container",
    "A receptacle, such as a carton, can, or jar, in which food is\n\
held or carried",
    "dry ice",
    "Solid carbon dioxide that sublimates at -78.5°C or -110°F and is\n\
used primarily as a coolant ",
    "beef",
    "Beef comes from the flesh of a slaughtered full-grown steer, bull,\n\
ox, or cow",
    "departments",
    "This is different areas of the store that sell merchandise\n\
that is unique to that area!",
    "flier",
    "Over the past couple of weeks customers have been reporting\n\
that they have seen some unusual things happen through out the\n\
store. We had one customer say he saw a mannequin jump off its\n\
stand and run back to receiving. Another customer stated that she\n\
saw an orange grow very large in just seconds and just roll to the\n\
back of the store. SO, BEWARE of what you may see it might attack!",

  });
  dest_dir =
  ({
    "/players/angel/area/walmart/room/bakery",      "bakery",
    "/players/angel/area/walmart/room/dairy",       "dairy",
    "/players/angel/area/walmart/room/deli",        "deli",
    "/players/angel/area/walmart/room/meats",        "meat",
    "/players/angel/area/walmart/room/produce",     "produce",
    "/players/angel/area/walmart/room/seafoods",     "seafood",
    "/players/angel/area/walmart/room/isle",        "aisle",
  });
}

realm(){ return "NT"; }