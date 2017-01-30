/*                                                                            *
 *      File:             /players/angel/area/town/room/mcdonalds.c           *
 *      Function:         Heal shop                                           *
 *      Author(s):        Angel@Nirvana                                       *
 *      Copyright:        Copyright (c) 2006 Angel                            *
 *                                All Rights Reserved.                        *
 *      Source:           11/20/06                                            *
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
  short_desc = "McDonald's";
  long_desc =
"    "+HIB+"McDonald's"+NORM+".\n\
  This is the local McDonald's fast food restaurant.  They serve\n\
such favorites as Egg McMuffin sandwiches for breakfast and Big\n\
Mac sandwiches and french fries for lunch.  The 'menu' is on the\n\
wall behind the counter.  Ronald and his friends are on the stage\n\
performing a magic show for all to enjoy.\n";

items =
  ({
  "menu",
  "Type 'menu' to see what you can order",
  "stage",
  "A low platform across from the playroom",
  "counter",
  "A long shelf with registers",
  });
  dest_dir =
  ({
    "/players/angel/area/town/room/emain_09",     "road",
  });
}

init()
  {
  ::init();
  add_action("buy_it","buy");
  add_action("list_it","menu");
  add_action("list_it","list");
  add_action("enter","stage");
  }
  list_it()
  {
  write(
      "       ()()()()()()()()()()()()()\n\
                LUNCH MENU\n\
       1."+HIM+" Big Mac"+NORM+BOLD+"                 3600"+NORM+"\n\
       2."+HIB+" Double Cheese burger"+NORM+BOLD+"    1200"+NORM+"\n\
       3."+HIY+" Fries"+NORM+BOLD+"                   1280"+NORM+"\n\
       4."+MAG+" Coke"+NORM+BOLD+"                    1600"+NORM+"\n\
              BREAKFAST MENU\n\
       5."+HIY+" Egg McMuffin"+NORM+BOLD+"            1500"+NORM+"\n\
       6."+BROWN+" Hash Brown"+NORM+BOLD+"              960"+NORM+"\n\
       ()()()()()()()()()()()()()\n\
       Please '"+GRN+"buy #"+NORM+"'.\n\n");
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
  if(!buy){ write("Please use: buy 1-6.\n"); return 1; }
  }
  switch(buy)
  {
  case "1"  :
    cost = 3600;
    item = clone_object("/players/angel/area/town/obj/bm.c");
    what = "Big Mac";
    break;
  case "2"  :
    cost = 1200;
    item = clone_object("/players/angel/area/town/obj/dcb.c");
    what = "Double Cheese burger";
    break;
  case "3"  :
    cost = 1280;
    item = clone_object("/players/angel/area/town/obj/fries.c");
    what = "Fries";
    break;
  case "4"  :
    cost = 1600;
    item = clone_object("/players/angel/area/town/obj/coke.c");
    what = "Coke";
    break;
  case "5"  :
    cost = 1500;
    item = clone_object("/players/angel/area/town/obj/emm.c");
    what = "Egg McMuffin";
    break;
  case "6"  :
    cost = 960;
    item = clone_object("/players/angel/area/town/obj/hb.c");
    what = "Hash brown";
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

enter(str) {
	say(capitalize(this_player()->query_name())+
    "walks onto the stage!\n");
    this_player()->move_player(
    "walks onto the stage to see the show #/players/angel/area/town/room/stage.c");
    say(capitalize(this_player()->query_name())+" arrives.\n");
    return 1;
}