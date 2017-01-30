#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_id("diamond");
   set_alias("diamond");
   set_short("A diamond");
   set_long("A sparkling diamond.\n"+
      "Perhaps you can "+HIW+"cash"+NORM+" it in somewhere.\n");
   set_weight(1);
   set_value(1900+random(200));
}
init(){
   ::init();
   
   add_action("cash","cash");
   
}

cash(arg){      
   int cost, diamond;
   diamond = present("diamond",environment(TO));
   cost = diamond->query_value();
   if(arg == "diamond"){
      if(present("jeweller",environment(TP))){
         write("The Jeweller gives you "+HIY+""+cost+""+NORM+" coins for the diamond.\n");
         call_other(this_player(), "add_money", cost);
         destruct(diamond);
         return 1; }
      if(present("melody",environment(TP))){
         write("Melody flashes you a charming smile and drops "+HIY+cost+NORM+" coins into your hand.\n");
         call_other(this_player(), "add_money", cost);
         destruct(diamond);
         return 1; }
      if(present("jeweler",environment(TP))){
         write("The Jeweler gives you "+HIY+cost+NORM+" coins for the "+HIW+"diamond"+NORM+".\n");
         call_other(this_player(), "add_money", cost);
         destruct(diamond);
         return 1; }
   }
   notify_fail("You can "+HIW+"cash diamond"+NORM+" at any jeweler, or with Melody.\n"); return 0; }

