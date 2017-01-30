#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

int num;
string *rooms;

reset(arg)  {
   if(arg) return;
   
   set_id("machine");
   set_short(HIB+"A vending machine"+NORM);
   set_long("A tall metal vending machine with a poster stuck\n"+
      "to the front.  You can look at the <list> of items\n"+
      "on the machine to <buy>.\n");
   set_weight(0);
   set_value(0);
}
init(){
   ::init();
   add_action("cmd_buy","buy");
   add_action("cmd_list","list");
}

coin_msg(){
   write("You do not have enough coins.\n");
}

cmd_buy(arg){
   if(arg == "spill" || arg == "drinking pill"){
      if(TP->query_money() < 1800){ coin_msg(); return 1; }
      TP->add_money(-1800);
      write("You purchase a pill pack from the machine.\n");
      say(TPN+" purchases a pill pack from the machine.\n");
      MOCO("/players/jaraxle/3rd/alt/items/soak.c"),TP);
return 1; }

 if(arg == "fpill" || arg == "eating pill"){
if(TP->query_money() < 1800){ coin_msg(); return 1; }
      TP->add_money(-1800);
      write("You purchase a pill pack from the machine.\n");
say(TPN+" purchases a pill pack from the machine.\n");
      MOCO("/players/jaraxle/3rd/alt/items/stuff.c"),TP);
return 1; }

 if(arg == "dpill" || arg == "detoxifying pill"){
if(TP->query_money() < 2800){ coin_msg(); return 1; }
      TP->add_money(-2800);
      write("You purchase a pill pack from the machine.\n");
say(TPN+" purchases a pill pack from the machine.\n");
      MOCO("/players/jaraxle/3rd/alt/items/detox.c"),TP);
return 1; }
notify_fail("Type 'list' to see what you can 'buy'\n"); return 0; }

cmd_list(){
write("\n  ITEM       DESC.            COST\n"+
"[ spill (drinking pill)    1800 coins ]\n"+
"[ fpill (eating pill)      1800 coins ]\n"+
"[ dpill (detoxifying pill) 2800 coins ]\n");
return 1; }

get(){
   write("Get what?\n");
   return 0; }
