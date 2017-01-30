/*                                                                            *
 *      File:             /players/angel/area/town/room/daves.c               *
 *      Function:         Heal shop                                           *
 *      Author(s):        Angel@Nirvana                                       *
 *      Copyright:        Copyright (c) 2007 Angel                            *
 *                                All Rights Reserved.                        *
 *      Source:           06/20/07                                            *
 *      Notes:            Heal shop                                           *
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
  short_desc = "Double Daves";
  long_desc =
"    "+HIB+"Double Daves"+NORM+".\n\
  Welcome to Double Daves.  We have a nice dine-in area with many\n\
cushioned booths.  There is a large buffet table in the center\n\
of the room with salad, pizza, pasta, and our famous pizza rolls.\n\
In the corner of the room is a large soda machine.  You may order\n\
pizza to go at the counter from the 'menu'.\n";

  items =
  ({
	"booths",
	"A large table with two cushioned benches on each side",
	"table",
	"It is a long rectangular wood counter",
	"machine",
	"It is out of order",
	"counter",
	"A long grey board made out of MDF",
	"mdf",
	"Medium-density fiberboard is an inexpensive plywood",
	"MDF",
	"Medium-density fiberboard is an inexpensive plywood",
  });
  dest_dir =
  ({
    "/players/angel/area/town/room/emain_07",  "road",
  });
}

init()
  {
  ::init();
  add_action("buy_it","buy");
  add_action("list_it","menu");
  add_action("list_it","list");
  }
  list_it()
  {
  write(
      "       ()()()()()()()()()()()()()\n\
             Pizza Menu\n\
\n\
       1."+HIM+" Pizza Rolls"+NORM+BOLD+"       3600"+NORM+"\n\
       2."+HIB+" Large Pizza"+NORM+BOLD+"       3300"+NORM+"\n\
       3."+HIY+" Small Pizza"+NORM+BOLD+"       1440"+NORM+"\n\
       ()()()()()()()()()()()()()\n\
             Please '"+GRN+"buy #"+NORM+"'\n\n");
  return 1;
  }

  buy_it(string str)
  {
  int buy;
  buy = str;
  if(!present("cashier"))
  {
  write("I'm sorry you don't see the cashier here.\n");
  return 1;
  if(!buy){ write("Please use: buy 1-3.\n"); return 1; }
  }
  switch(buy)
  {
  case "1"  :
    cost = 3600;
    item = clone_object("/players/angel/area/town/obj/pr.c");
    what = "Pizza Rolls";
    break;
  case "2"  :
    cost = 3300;
    item = clone_object("/players/angel/area/town/obj/lp.c");
    what = "Large Pizza";
    break;
  case "3"  :
    cost = 1440;
    item = clone_object("/players/angel/area/town/obj/sp.c");
    what = "Small Pizza";
    break;
  default:
    write("Sorry, We don't have that.\n");
    return 1;
  }
  if (call_other(this_player(), "query_money", 0) < cost)
    {
    write("Cashier tells you: You do not have enough money for that.\n");
    return 1;
    }
    if(!this_player()->add_weight(item->query_weight()))
    {
      write("Cashier tells you: You can't carry that much.\n");
      destruct(item);
      return 1;
    }
    write("You give the cashier "+cost+" coins and receive a "+what+".\n");
    say(this_player()->query_name() + " buys a "+what+".\n");
    move_object(item,this_player());
    this_player()->add_money(-(cost));
    return 1;
}