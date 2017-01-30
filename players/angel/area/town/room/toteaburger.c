/*                                                                            *
 *      File:             /players/angel/area/town/room/toteaburger.c         *
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

string what;
int cost;
object item, cashier;

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
  short_desc = "Tote-A-Burger";
  long_desc =
"    "+HIB+"Tote-A-Burger"+NORM+".\n\
  Mouth watering food, great portions and a fun atmosphere make\n\
Tote-A-Burger a favorite of young and old alike. Tote-A-Burger is\n\
famous for their Smoked Meat Sandwiches, but also offers a wide\n\
selection of gourmet pizzas, fresh tenderloin, juicy burgers and\n\
more. A bar is also available for our adult guests, offering your\n\
favorite wine and beer and served by the friendliest bartenders\n\
in town.  The menu 'list' the prices for these great items.\n";

  items =
  ({
    "bar",
    "It's a basic area where alcohol is served",
  });
  dest_dir =
  ({
    "/players/angel/area/town/room/hw_356",     "highway",
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
            Item                   Price\n\
\n\
         1. Tenderloin           5000 coins\n\
\n\
         2. BBQ sausage          5000 coins\n\
\n\
         3. Mushroom Burger      2000 coins\n\
\n\
         4. White wine           1500 coins\n\
\n\
         5. Budweiser            1000 coins\n\
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