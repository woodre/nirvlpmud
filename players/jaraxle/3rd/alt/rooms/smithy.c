#include "/players/jaraxle/define.h"
#include "/players/jaraxle/3rd/alt/mobs/random.h"
inherit "/players/jaraxle/3rd/alt/rooms/room2.c";

reset(arg) {
   if(arg) return;
   set_light(0);
   short_desc = BLK+BOLD+"The smithy"+NORM;
   long_desc =
   "  A small shack of a store.  The tattered shelves\n"+
   "are lined with old equipment and covered in dust.\n"+
   "The counter has seen more than its share of wear\n"+
   "and tear.  There is a large sign dangling from\n"+
   "the side wall.\n";
   add_item("shelves","Long wooden shelves to hold equipment");
   add_item("equipment","Type 'list' to see what is available");
   add_item("counter","A large oak counter with plenty of age");
   add_item("sign","A large sign, hanging by one nail that reads: 'list'");
   add_object("/players/jaraxle/3rd/alt/mobs/smithy.c");
   add_exit("/players/jaraxle/3rd/alt/rooms/northroad1.c","east");
   
}


init(){
   ::init();
   
   add_action("browse_it", "list");
   add_action("purchase_it","buy");
}

browse_it(){
   write(
      " You browse the store's selection....\n\n"+
      "     ________________________________________________________  \n"+
      "     ____Item________________________________________Cost____  \n\n"+
      "     1. "+BOLD+"A Great Helm......................................300"+NORM+"  \n"+
      "     2. "+BOLD+"Shield w/ Red Cross...............................600"+NORM+"  \n"+
      "     3. "+BOLD+"Squires Boots......................................50"+NORM+"  \n"+
      "     4. "+BOLD+"Squires Leather Armor.............................150"+NORM+"  \n"+
      "     5. "+BOLD+"Full PlateArmor..................................5000"+NORM+"\n"+
      "     ________________________________________________________  \n"+
      "     You may '"+BOLD+"buy #"+NORM+"'\n");
   return 1;
}

purchase_it(string str){
   object what;
   object item;
   int cost;
   int purchase;
   purchase = str;
   
   if(!purchase){ write("Usage: purchase 1-5.\n"); return 1; }
   
   if(purchase == "1"){
      cost = 300;
      item = clone_object("/players/jaraxle/templar/items/helmet.c");
      what = "great helm";
   }
   else if(purchase == "2"){
      cost = 600;
      item = clone_object("/players/jaraxle/templar/items/shield.c");
      what = "shield";
   }
   else if(purchase == "3"){
      cost = 50;
      item = clone_object("/players/jaraxle/templar/items/sboots.c");
      what = "pair of squires boots";
   }
   else if(purchase == "4"){
      cost = 150;
      item = clone_object("/players/jaraxle/templar/items/larmor.c");
      what = "suit of leather armor";
   }
   else if(purchase == "5"){
      cost = 5000;
      item = clone_object("/players/jaraxle/templar/items/fullplate2.c");
      what = "suit of plate armor";
   }
   
   else{
      write("The smithy says: I'm sorry, we don't carry that.\n");
      return 1;
   }       
   
   if (call_other(this_player(), "query_money", 0) < cost) {
      write("The store owner says: I'm sorry, but you don't have enough for that.\n");
      return 1;
   }          
   
   if(!this_player()->add_weight(item->query_weight())) {
      write("The store owner says: It doesn't look like you can carry that.\n");
      destruct(item);
      return 1; }                 
   
   write("You pay the store owner "+cost+" coins and receive a "+what+".\n");
   say(TP->query_name() + " purchases a "+what+".\n");
   move_object(item,this_player());
   TP->add_money(-(cost));
   return 1;
}   
