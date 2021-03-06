/*                                                                              *
 *      File:             /players/angel/area/walmart/room/hardlines.c          *
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


reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = HIB+"Hardlines Isle"+NORM;
  long_desc =
"   "+HIB+"Hardlines"+NORM+"\n\
  Dress up your home with a wide selection of home items, all at\n\
Walmart. For stylish, functional living, find our juicers,\n\
microwaves, compact refrigerators and our popular George Foreman\n\
grills for less. You'll also find a great selection of  sewing\n\
machines,  air conditioners and compact washers and dryers, all\n\
at Wal-Mart's Every Day Low Prices. You may browse all of the\n\
different departments but, "+HIR+"BEWARE"+NORM+" of the "+HIM+"strange happenings!"+NORM+"\n\
There is a flier hanging on the wall that you can 'look' at!\n";
  items =
  ({
    "home",
    "A place where one lives. A home is where your heart is!",
    "walmart",
    "Wal-Mart is a large retailer bent on overtaking the world!",
    "juicer",
    "An appliance that is used to extract juice from fruits and vegetables",
    "microwave",
    "An appliance that it used to heat up food quickly",
    "refrigerator",
    "An appliance that it used to keep foods cold ",
    "grill",
    "An appliance that it used to cook food",
    "washer",
    "An appliance that it used to clean clothes",
    "dryer",
    "An appliance that it used to dry wet clothes",
    "sewing machine",
    "An appliance that it used to mend or make clothes and other items made of fabric",
    "air conditioner",
    "An appliance that it used to cool down a home",
    "department",
    "This is different areas of the store that sell merchandise\n\
that is unique to that area!",
#if 0 /* Rumplemintz - fixing to match long_desc */
    "flyier",
#else
    "flier",
#endif
    "Over the past couple of weeks customers have been reporting\n\
that they have seen some unusual things happen through out the\n\
store. We had one customer say he saw a mannequin jump off its\n\
stand and run back to receiving. Another customer stated that she\n\
saw an orange grow very large in just seconds and just roll to the\n\
back of the store. SO, BEWARE of what you may see it might attack!",
    

  });
  dest_dir =
  ({
    "/players/angel/area/walmart/room/automotives",       "auto",
    "/players/angel/area/walmart/room/electronics",       "electronics",
    "/players/angel/area/walmart/room/gardencenter",      "garden",
    "/players/angel/area/walmart/room/hardware",          "hardware",
    "/players/angel/area/walmart/room/sportinggoods",     "sporting",
    "/players/angel/area/walmart/room/toys",              "toys",
    "/players/angel/area/walmart/room/isle",              "aisle",
  });
}

realm(){ return "NT"; }
