/* borrowed from the great Eurale */
#include "/players/pestilence/ansi.h"
#include "/players/pestilence/define.h"
#define ETO environment(this_object())
inherit "obj/treasure";
int VSHAKE,CSHAKE,PIE, soldout;
object item;
int cost;
string what;


reset(arg)  {
VSHAKE = 0;
PIE = 0;
CSHAKE = 0;
  if(arg) return;
    set_id("counter");
    set_weight(0);
    set_value(0);
call_out("poison_player",550);
}

init () {
   ::init() ;
     add_action ("buy_it","buy");
     }


poison_player() {
    VSHAKE = 0;
    PIE = 0;
    CSHAKE = 0;
    call_out("poison_player",600);
    return 1; }



drop() { return 1; }
get() { return 0; }




buy_it(string str){
   if(!str){ write("Buy 1-9"); return 1; }
   if(str == "1"){
      cost = 1800;
      item = clone_object("/players/pestilence/amity/obj/hamburger.c");
      what = "hamburger";
   }
   else if(str == "2"){
      cost = 1800;
      item = clone_object("/players/pestilence/amity/obj/pepsi.c");
      what = "pepsi";
   }
   else if(str == "3"){
if(VSHAKE > 25){ write("The Vanilla shakes are all sold out.\n"); return 1;}
      cost = 1800;
      item = clone_object("/players/pestilence/amity/obj/vshake.c");
      soldout = VSHAKE += 1;
      what = "vanilla milkshake";
   }
   else if(str == "4"){
if(CSHAKE > 25){ write("The chocolate shakes are all sold out.\n"); return 1;}
      cost = 2100;
      item = clone_object("/players/pestilence/amity/obj/cshake.c");
      soldout = CSHAKE += 1;
      what = "chocolate milkshake";
   }
   else if(str == "5"){
      cost = 2100;
      item = clone_object("/players/pestilence/amity/obj/fries.c");
      what = "french fries";
   }
   else if(str == "6"){
      cost = 2100;
      item = clone_object("/players/pestilence/amity/obj/hotdog.c");
      what = "hotdog";
   }
   else if(str == "7"){
if(PIE > 25){ write("The Pies are all sold out.\n"); return 1;}
      cost = 1200;
      item = clone_object("/players/pestilence/amity/obj/bpie.c");
      soldout = PIE += 1;
      what = "blackberry pie";
   }
   else if(str == "8"){
      cost = 3300;
      item = clone_object("/players/pestilence/amity/obj/lvshake.c");
/*
      soldout = VSHAKE += 1;
*/
      what = "lowfat vanilla milkshake";
   }
   else if(str == "9"){
if(PIE > 25){ write("The Pies are all sold out.\n"); return 1;}
      cost = 1200;
      item = clone_object("/players/pestilence/amity/obj/bluepie.c");
      soldout = PIE += 1;
      what = "blueberry pie";
   }
   else{
      write("The choices are 1-9.\n");
      return 1;
   }     
   if (call_other(this_player(), "query_money", 0) < cost) {
      write("I'm sorry, but you don't have enough coins for that.\n");
      return 1;
   } 
/*
if(VSHAKE > 35){ write("They are all sold out right now.\n"); return 1;}
*/
   if(!this_player()->add_weight(item->query_weight())) {
      write("It doesn't look like you can carry that.\n");
      destruct(item);
      return 1; }                 
   write("You pay "+cost+" coins for a "+what+".\n");
   say(tp->query_name() + " purchases a "+what+".\n");
      soldout;
   move_object(item,this_player());
   tp->add_money(-cost);
   return 1;
}
