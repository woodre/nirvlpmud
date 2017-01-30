/*                                                                            *
 *      File:             /players/angel/area/town/room/handyandy.c           *
 *      Function:         room                                                *
 *      Author(s):        Angel@Nirvana                                       *
 *      Copyright:        Copyright (c) 2007 Angel                            *
 *                                All Rights Reserved.                        *
 *      Source:           06/20/07                                            *
 *      Notes:            Fake Heal Shop                                      *
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
    move_object(clone_object("/players/angel/area/town/npc/cashier_02.c"), this_object());
  if(arg) return;
  set_light(1);
  short_desc = "Handy Andy";
  long_desc =
"    "+HIB+"Handy Andy"+NORM+".\n\
  This is a local convenience store.  The aisles are filled\n\
with household staple items.  The coolers along the walls\n\
are filled with every drink you could want.  The counter at\n\
the front door has two registers and a candy counter in front.\n\
The cashier has a 'list' of all the prices.\n";

  items =
  ({
	"store",
	"It sells convenient items",
	"aisle",
	"counters filled with products",
	"cooler",
	"tall refrigerated machine with glass doors",
	"walls",
	"There are four of them all around the room",
	"counter",
	"A short shelf with a register on them",
	"door",
	"The doors swing open with ease. They are made of glass",
	"register",
	"It looks really heavy",
	"registers",
	"They look really heavy",
  });
  dest_dir =
  ({
    "/players/angel/area/town/room/emain_02",  "road",
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
         1. Gatorade            2000 coins\n\
\n\
         2. Coke                2000 coins\n\
\n\
         3. Kit Kat             1500 coins\n\
\n\
         4. Twix                1000 coins\n\
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