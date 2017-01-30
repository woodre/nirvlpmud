inherit "room/room";
#include <ansi.h>


string what;
int cost;
object item, bob;

reset(arg) 
{
  ::reset(arg);	
  if( !present("bob", this_object()) )
    move_object(clone_object("/players/angel/area/walmart/npc/walmart_associate_01.c"), this_object());
  if(arg) return;
  set_light(1);
  short_desc = HIB+"Wal-Mart SuperCenter"+NORM;
  long_desc =
    "  This appears to be a local Wal-Mart SuperCenter. The shelves\n\
have several grocery items available for you to purchase. To see\n\
what food items the store has available to offer, you could look\n\
at the 'shelves'. If someone wish's to browse through the store\n\
they could 'enter' it!\n";
/*
Wal-Mart stores are stocked with the latest products and fun, info-packed events.
*/

  items =
  ({
  "shelf",
"()()()()()()()()\n\
"+HIY+" Chunk Cheese"+NORM+BOLD+"\n\
"+RED+" Capri Sun"+NORM+BOLD+"\n\
"+HIB+" GoGurt"+NORM+BOLD+"\n\
"+MAG+" Kahlua"+NORM+BOLD+"\n\
"+HIY+" Cheese Wiz"+NORM+BOLD+"\n\
"+HIG+" Popcorn Chicken"+NORM+BOLD+"\n\
()()()()()()()()\n\
Type 'shelf' to check availability",
  "shelves",
"()()()()()()()()\n\
"+HIY+" Chunk Cheese"+NORM+BOLD+"\n\
"+RED+" Capri Sun"+NORM+BOLD+"\n\
"+HIB+" GoGurt"+NORM+BOLD+"\n\
"+MAG+" Kahlua"+NORM+BOLD+"\n\
"+HIY+" Cheese Wiz"+NORM+BOLD+"\n\
"+HIG+" Popcorn Chicken"+NORM+BOLD+"\n\
()()()()()()()()\n\
Type 'shelves' to check availability",
  });
  dest_dir = 
  ({
/*  "/players/angel/area/school/room/airport.c",   "heli2",*/
    "/players/angel/area/town/room/emain_10.c",    "south",
  });
}

query_no_fight(){
  return 1;
}

init()
  {
  ::init();
  add_action("buy_it","buy");
  add_action("list_it","shelves");
  add_action("list_it","shelf");
  add_action("enter","enter");
  add_action("walk","road");
  }
  list_it()
  {
  write(
      "       ()()()()()()()()()()()()()\n\
       1."+HIY+" Chunk Cheese"+NORM+BOLD+"       4400"+NORM+"\n\
       2."+RED+" Capri Sun"+NORM+BOLD+"          2800"+NORM+"\n\
       3."+HIB+" GoGurt"+NORM+BOLD+"             2800"+NORM+"\n\
       4."+MAG+" Kahlua"+NORM+BOLD+"             4000"+NORM+"\n\
       5."+HIY+" Cheese Wiz"+NORM+BOLD+"         1800"+NORM+"\n\
       6."+HIG+" Popcorn Chicken"+NORM+BOLD+"     960"+NORM+"\n\
       ()()()()()()()()()()()()()\n\
       Please '"+GRN+"buy #"+NORM+"'.\n\n");
  return 1;
  }
      
  buy_it(string str)
  {
  int buy;
  buy = str;
  if(!present("bob"))
  {
  write("I'm sorry you don't see the shopkeeper here.\n");
  return 1;
  if(!buy){ write("Please use: buy 1-6.\n"); return 1; }
  }
  switch(buy)
  {
  case "1"  :
    cost = 4400;
    item = clone_object("/players/angel/area/walmart/obj/chunck_cheese_01.c");
    what = "block of cheese";
    break;
  case "2"  :
    cost = 2800;
    item = clone_object("/players/angel/area/walmart/obj/capri_sun_01.c");
    what = "pouch of juice";
    break;
  case "3"  :
    cost = 2800;
    item = clone_object("/players/angel/area/walmart/obj/gogurt_01.c");
    what = "tube of gogurt";
    break;
  case "4"  :
    cost = 4000;
    item = clone_object("/players/angel/area/walmart/obj/kahlua_01.c");
    what = "four pack of an exotic mexican drink";
    break;
  case "5"  :
    cost = 1800;
    item = clone_object("/players/angel/area/walmart/obj/cheese_wiz_01.c");
    what = "wiz in a can";
    break;
  case "6"  :
    cost = 960;
    item = clone_object("/players/angel/area/walmart/obj/popcorn_chicken_01.c");
    what = "cup of popcorn chicken";
    break;
  default:
    write("Sorry, We don't have that.\n");
    return 1;
  }
  if (call_other(this_player(), "query_money", 0) < cost) 
    {
    write("Bob tells you: You do not have enough money for that.\n");
    return 1;
    }          
    if(!this_player()->add_weight(item->query_weight())) 
    {
      write("Bob tells you: You can't carry that much.\n");
      destruct(item);
      return 1;
    }  
    write("You give Bob "+cost+" coins and receive a "+what+".\n");                
    say(this_player()->query_name() + " buys a "+what+".\n");
    move_object(item,this_player());
    this_player()->add_money(-(cost));
    return 1;
}

enter(str) {
	say(capitalize(this_player()->query_name())+
    "walks past the counter and into the store isle.\n");
    this_player()->move_player(
    "walks down the isle browsing #/players/angel/area/walmart/room/isle.c");
    say(capitalize(this_player()->query_name())+" arrives.\n");
    return 1;
}

walk() {
    if (call_other(this_player(), "query_level", 0) < 20) {
        write("A strong magic force stops you.\n");
        say(call_other(this_player(), "query_name", 0) +
            " tries to go through the field, but fails.\n");
        return 1;
    }
    write("You wriggle through the force field...\n");
    call_other(this_player(), "move_player", "fly#/players/angel/area/town/room/emain_10.c");
    return 1;
}
