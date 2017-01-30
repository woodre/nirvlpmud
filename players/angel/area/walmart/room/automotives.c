/*                                                                              *
 *      File:             /players/angel/area/walmart/room/automotivies.c       *
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
  if( !present("blaster", this_object()) )
    move_object(clone_object("/players/angel/area/walmart/npc/blaster.c"), this_object());  
  if( !present("blurr", this_object()) )
  {
    for(x=0; x<1; x++)
    {
    move_object(clone_object("/players/angel/area/walmart/npc/transformer.c"), this_object());
    }
}
if(arg) return;
  set_light(1);
  short_desc = HIB+"Automotives department"+NORM;
  long_desc =
"   "+HIB+"Automotive Department"+NORM+"\n\
  Wal-Mart Tire & Lube Express offers high-quality expert care\n\
and services for your vehicle at more than 2,000 locations\n\
nationwide. Our Installation and Tire Protection Plan is one\n\
of the best values anywhere. We'll give you peace of mind and\n\
keep you on the road without costing you a fortune. We're confident\n\
that our tires are the best values in the business. Enjoy the ride!\n";

  items =
  ({
    "walmart",
    "Wal-Mart is a large retailer bent on overtaking the world!",
    "tire",
    "A covering for a wheel, made of rubber reinforced with cords\n\
of nylon, fiberglass, or other material, filled with compressed air",
    "lube",
    "A lube job replaces grease between parts of your vehicle that\n\
rub together",
    "expert",
    "This is a person with a high degree of skill and knowledge in automotive's",
    "vechicle",
    "People leave cars and trucks for a lube job",
    "plan",
    "Our plan provides insurance in the event the tires wears or breaks",
    "road",
    "An open, generally public way for the passage of vehicles",
    "fortune",
    "More money than you have or will ever see!",
    "business",
    "A commercial enterprise",

  });
  dest_dir =
  ({
    "/players/angel/area/walmart/room/hardlines", "hardlines",
  });
}

realm(){ return "NT";}