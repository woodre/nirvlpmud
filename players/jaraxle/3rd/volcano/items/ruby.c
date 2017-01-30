#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_id("rubies");
   set_alias("eyes");
   set_short(HIR+"Rubies"+NORM);
   set_long("A pair of "+HIR+"rubies"+NORM+" in the shape of round eyes.\n"+
      "Perhaps you can "+HIW+"cash"+NORM+" them in somewhere.\n");
   set_weight(1);
   set_value(1600+random(400));
}
init(){
   ::init();
   
   add_action("cash","cash");
   
}

cash(arg){      
   int cost, rubies;
   rubies = present("rubies",environment(TO));
   cost = rubies->query_value();
   if(arg == "rubies"){
      if(present("jeweller",environment(TP))){
         write("The Jeweller gives you "+HIY+""+cost+""+NORM+" coins for the "+HIR+"rubies"+NORM+".\n");
         call_other(this_player(), "add_money", cost);
         destruct(rubies);
         return 1; }
      if(present("jeweler",environment(TP))){
         write("The Jeweller gives you "+HIY+cost+NORM+" coins for the "+HIR+"rubies"+NORM+".\n");
         call_other(this_player(), "add_money", cost);
         destruct(rubies);
         return 1; }
      if(present("melody",environment(TP))){
         write("Melody flashes you a charming smile and drops "+HIY+cost+NORM+" coins into your hand.\n");
         call_other(this_player(), "add_money", cost);
         destruct(rubies);
         return 1; }
   }
   notify_fail("You can "+HIW+"cash rubies"+NORM+" at any jeweler, or with Melody.\n"); return 0; }
