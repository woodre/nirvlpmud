/*                                                                            *
 *      File:             /players/angel/area/town/room/cvs.c                 *
 *      Function:         room                                                *
 *      Author(s):        Angel@Nirvana                                       *
 *      Copyright:        Copyright (c) 2007 Angel                            *
 *                                All Rights Reserved.                        *
 *      Source:           06/20/07                                            *
 *      Notes:            Fake Heal shop                                      *
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
  if( !present("mmulti02", this_object()) )
    move_object(clone_object("/players/angel/area/town/npc/multi_02.c"), this_object());
  if( !present("multi", this_object()) )
    move_object(clone_object("/players/angel/area/town/npc/multi.c"), this_object());
  if( !present("cashier", this_object()) )
    move_object(clone_object("/players/angel/area/town/npc/cashier.c"), this_object());
  if(arg) return;
  set_light(1);
  short_desc = "CVS";
  long_desc =
"    "+HIB+"CVS"+NORM+".\n\
  This is the local CVS pharmacy.  The pharmacy carries medicines for\n\
all types of problems. They are stored on shelves that is continuous\n\
around the corners.  There is an integrated computer workstation with\n\
flexible counter and storage space.  Check out the 'list' of items\n\
you can buy.\n";

  items =
  ({
	"pharmacy",
	"It is filled to the brim with medicine",
	"shelving",
	"long metal counters",
	"computer",
	"It's a Dell!",
	"workstation",
	"an area with computers for employees to work",
	"counter",
	"long metal shelves to hold merchandise",
	"merchandise",
	"many different products for sale",
  });
  dest_dir =
  ({
    "/players/angel/area/town/room/emain_02",     "road",
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
         1. Valium             10000 coins\n\
\n\
         2. Benadryl            5000 coins\n\
\n\
         3. Aspirin             2000 coins\n\
\n\
         4. Can of Coke         1000 coins\n\
\n\
         5. Snickers             500 coins\n\
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