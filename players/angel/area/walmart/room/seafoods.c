/*                                                                              *
 *      File:             /players/angel/area/walmart/room/seafoods.c           *
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
  if( !present("lobster", this_object()) )
  {
    for(x=0; x<2; x++)
    {
    move_object(clone_object("/players/angel/area/walmart/npc/lobster.c"), this_object());
    }
}
if(arg) return;
  set_light(1);
  short_desc = HIY+"Seafood Isle"+NORM;
  long_desc=
"   "+HIY+"Seafood department"+NORM+"\n\
  Fresh from the shore, straight to our store! That’s the promise\n\
you’ll get when shopping at the Seafood Markets in Wal-Mart. We offer\n\
everything from mussels, crab and seafood salads to boneless fillet's,\n\
lobster and ready-to-cook meals! No matter what your favorite seafood\n\
selection, you’re sure to find the freshest quality and the lowest\n\
prices at Wal-Mart!\n";

  items =
  ({
    "store",
    "A place where merchandise is offered for sale",
    "seafood",
    "Edible fish or shellfish from the sea",
    "market",
    "A place where goods are offered for sale",
    "walmart",
    "Wal-Mart is a large retailer bent on overtaking the world!",
    "mussels",
    "An edible blue-black species raised commercially in Europe",
    "crab",
    "An edible marine crustaceans",
    "salads",
    "A dish of raw leafy green vegetables",
    "fillet",
    "A boneless strip of meat or fish",
    "meals",
    "Food served and eaten in one sitting",

  });
  dest_dir =
  ({
    "/players/angel/area/walmart/room/foods", "foods",
  });
}
realm(){ return "NT"; }