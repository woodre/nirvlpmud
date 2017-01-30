/*                                                                            *
 *      File:             /players/angel/area/town/room/market.c              *
 *      Function:         room                                                *
 *      Author(s):        Angel@Nirvana                                       *
 *      Copyright:        Copyright (c) 2007 Angel                            *
 *                                All Rights Reserved.                        *
 *      Source:           06/20/07                                            *
 *      Notes:            Fake store                                          *
 *                                                                            *
 *                                                                            *
 *      Change History:                                                       *
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if( !present("customer", this_object()) )
    move_object(clone_object("/players/angel/area/town/npc/customer.c"), this_object());
  if( !present("multi02", this_object()) )
    move_object(clone_object("/players/angel/area/town/npc/multi_02.c"), this_object());
  if( !present("multi", this_object()) )
    move_object(clone_object("/players/angel/area/town/npc/multi.c"), this_object());
  if( !present("cashier", this_object()) )
    move_object(clone_object("/players/angel/area/town/npc/cashier.c"), this_object());
  if(arg) return;
  set_light(1);
  short_desc = "Flea Market";
  long_desc =
"    "+HIB+"Flea Market"+NORM+".\n\
  This is an indoor flea market.  It is a large open store.\n\
There is all kinds of merchandise available for purchase.\n\
Several areas of the store are set up like individual shops.\n\
The merchandise is sorted with like items.  The cashier may\n\
have a 'list' of items for sale.\n";

  items =
  ({
	"market",
	"A large open area with many different shops",
	"store",
	"A place to by merchandise",
	"merchandise",
	"Products you can buy to use or keep in your home",
	"shops",
	"small businesses",
	"items",
	"many different products to buy",
  });
  dest_dir =
  ({
    "/players/angel/area/town/room/wmain_02",  "road",
  });
}

init()
  {
  ::init();
  add_action("buy_it","buy");
  add_action("list_it","list");
  }
  
  list_it()
  {
  write(
      "      ()()()()()()()()()()()()()()()()()()()\n\
            Item                  Price\n\
\n\
         1. Gutar              10000 coins\n\
\n\
         2. Chair               5000 coins\n\
\n\
         3. Atari 2600          2000 coins\n\
\n\
         4. Pac Man             1000 coins\n\
\n\
         5. Combat               500 coins\n\
\n\
      ()()()()()()()()()()()()()()()()()()()\n\
              Please '"+GRN+"buy #"+NORM+"'\n\n");
  return 1;
  }

  buy_it(str)
  {
  if(!str) {
    notify_fail("What do you want to buy?\n");
    return 0;
  }
  else if(str) {
    write("Sorry, were out of stock.\n");
  }
  return 1;
}