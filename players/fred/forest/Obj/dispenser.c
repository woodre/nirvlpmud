#include "/players/fred/ansi.h"
inherit "/obj/treasure.c";

reset (arg) {
	set_id("dispenser");
	set_short(HIG+"A pill dispenser"+NORM);
	set_long(
      "  It looks like a candy dispenser with a small metal crank on it.\n"+
      " Type 'turn_crank'.\n");
}

init(){
  ::init();
     add_action("get_em","turn_crank");
  }

get(){ return; }

get_em(){
  int cost;
  string what;
  object item;
    cost = 150;
    item = clone_object("/players/fred/toys/pill.c");
    what = "small green pill";
 if (call_other(this_player(), "query_money", 0) < cost) {
    write("You do not have enough money ya cheap bastard!\n");
    return 1;
     }          
 if(!this_player()->add_weight(item->query_weight())) {
    write("You can't carry any more pills.\n");
    destruct(item);
    return 1; }  
 write("You drop "+cost+" coins into the dispenser and twist the crank.  Suddenly a "+what+" falls into your hand.\n");                
 say(this_player()->query_name() + " twist the crank and gets a "+what+".\n");
 move_object(item,this_player());
 this_player()->add_money(-(cost));
 return 1;
 }    

