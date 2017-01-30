#include <ansi.h>

inherit "room/room";

string what;
int cost;
object item, charle;

reset(arg) 
{
  ::reset(arg);	
  if( !present("charle", this_object()) )
    move_object(clone_object("/players/angel/masons/npc/charle.c"), this_object());
  if(arg) return;
  set_light(1);
  short_desc = HIY+"The Masons Pub"+NORM;
  long_desc =
"      This is the Masons take out bar.\n\
\n\
<------------------------------------------------->\n\
       1.  First Class Beer     ==>  25 gp\n\
       2.  Special of the House ==> 150 gp\n\
       3.  Firebreather         ==> 250 gp\n\
<------------------------------------------------>\n\
\n\
         You can order drinks here.\n";

  dest_dir = 
  ({
    "/players/angel/masons/ghall",             "down",
    "/players/angel/area/town/room/wmain_02",  "out",
  });
}

query_no_fight(){
  return 1;
}

init()
  {
  ::init();
  add_action("buy_it","buy");
}

  buy_it(string str)
  {
  int buy;
  buy = str;
  if(!present("charle"))
  {
  write("I'm sorry you don't see the barhop here.\n");
  return 1;
  if(!buy){ write("Please use: buy 1-3.\n"); return 1; }
  }
  switch(buy)
  {
  case "1"  :
    cost = 25;
    item = clone_object("/players/angel/masons/obj/beer.c");
    what = "First Class Beer";
    break;
  case "2"  :
    cost = 150;
    item = clone_object("/players/angel/masons/obj/special.c");
    what = "Special of the House";
    break;
  case "3"  :
    cost = 250;
    item = clone_object("/players/angel/masons/obj/fire.c");
    what = "Firebreather";
    break;
  default:
    write("Sorry, We don't have that.\n");
    return 1;
  }
  if (call_other(this_player(), "query_money", 0) < cost)
    {
    write("Charle tells you: You do not have enough money for that.\n");
    return 1;
    }
    if(!this_player()->add_weight(item->query_weight()))
    {
      write("Charle tells you: You can't carry that much.\n");
      destruct(item);
      return 1;
    }
    write("You give Charle "+cost+" coins and receive a "+what+".\n");
    say(this_player()->query_name() + " buys a "+what+".\n");
    move_object(item,this_player());
    this_player()->add_money(-(cost));
    return 1;
}