/*                                                                            *
 *      File:             /players/angel/area/town/room/flower.c              *
 *      Function:         Flower shop                                         *
 *      Author(s):        Angel@Nirvana                                       *
 *      Copyright:        Copyright (c) 2007 Angel                            *
 *                                All Rights Reserved.                        *
 *      Source:           06/20/07                                            *
 *      Notes:            Flower shop                                         *
 *                                                                            *
 *                                                                            *
 *      Change History:                                                       *
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "room/room";

string what;
int cost;
object item, florist;

reset(arg)
{
  ::reset(arg);
  if( !present("customer", this_object()) )
    move_object(clone_object("/players/angel/area/town/npc/customer.c"), this_object());
  if( !present("multi02", this_object()) )
    move_object(clone_object("/players/angel/area/town/npc/multi_02.c"), this_object());
  if( !present("multi", this_object()) )
    move_object(clone_object("/players/angel/area/town/npc/multi.c"), this_object());
  if( !present("florist", this_object()) )
    move_object(clone_object("/players/angel/area/town/npc/florist.c"), this_object());
  if(arg) return;
  set_light(1);
  short_desc = "Joannie's Flower Shop";
  long_desc =
"    "+HIB+"Joannie's Flower Shop"+NORM+".\n\
  Flowers surround everything in this shop.  There are many types\n\
of flowers here.  This shop is very busy with high traffic.  It\n\
is very well known for its high quality of flowers and large array\n\
of inventory.  One might be able to 'buy' some flowers for a special\n\
occasion.  Items 'list'ed on a small board are available.\n";

  items =
  ({
	"shop",
	"A quaint store filled with flowers",
	"flowers",
	"large varieties all over the room",
	"board",
	"It lists flowers and their prices",
  });
  dest_dir =
  ({
    "/players/angel/area/town/room/emain_03",     "road",
  });
}

init()
  {
  ::init();
  add_action("buy_it","buy");
  add_action("list_it","board");
  add_action("list_it","list");
  }
  list_it()
  {
  write(
  "          ()()()()()()()()()()()()()()()()()\n\
                 Flowers            Price\n\
\n\
            1.  Red Rose           50 coins\n\
            2.  A Large RED ROSE  100 coins\n\
\n\
          ()()()()()()()()()()()()()()()()()\n\
                 Please '"+HIB+"buy #"+NORM+"'.\n\n");
  return 1;
  }

  buy_it(string str)
  {
  int buy;
  buy = str;
  if(!present("florist"))
  {
  write("I'm sorry you don't see the cashier here.\n");
  return 1;
  if(!buy){ write("Please use: buy 1 or 2.\n"); return 1; }
  }
  switch(buy)
  {
  case "1"  :
    cost = 50;
    item = clone_object("/players/angel/area/town/obj/red_rose.c");
    what = "red rose";
    break;
  case "2"  :
    cost = 100;
    item = clone_object("/players/angel/area/town/obj/l_rose.c");
    what = "a large rose";
    break;
  default:
    write("Sorry, We don't have that.\n");
    return 1;
  }
  if (call_other(this_player(), "query_money", 0) < cost)
    {
    write("The Florist tells you: You do not have enough money for that.\n");
    return 1;
    }
    if(!this_player()->add_weight(item->query_weight()))
    {
      write("The Florist tells you: You can't carry that much.\n");
      destruct(item);
      return 1;
    }
    write("You give the florist "+cost+" coins and receive a "+what+".\n");
    say(this_player()->query_name() + " buys a "+what+".\n");
    move_object(item,this_player());
    this_player()->add_money(-(cost));
    return 1;
}