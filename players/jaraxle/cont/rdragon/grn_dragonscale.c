/*  Green Dragon Scales - Worth 1k each. */

inherit "obj/treasure";

#include "/players/jaraxle/define.h"


reset(arg){
   
   if(arg) return;
   set_short(GRN+"a dragonscale"+NORM);
   set_long(
      "This is a large scale from a Emerald Dragon. It can be\n"+
      "sold, or perhaps you might find another use for it.\n");
   set_weight(1);
   set_value(2000+random(1600));
}

id(str){ return str == "scale" || str == "dragonscale" || 
   str == "green_dragon_scale";  } 

init(){
   ::init();
   
   add_action("trade","trade");
   
}

trade(arg){      
   int cost, blue_dragon;
   blue_dragon = present("green_dragon_scale",environment(TO));
   cost = blue_dragon->query_value();
   if(arg == "scale"){
      if(present("archeologist",environment(TP))){
         write("The Archeologist gives you "+HIY+""+cost+""+NORM+" coins for the"+
            " Dragon Scales.\n");
         call_other(this_player(), "add_money", cost);
         destruct(blue_dragon);
         return 1; }
      if(present("Ahna",environment(TP))){
         write("Ahna flashes you a charming smile and drops "+HIY+"coins"+NORM+""+
            " coins into your hand.\n");
         call_other(this_player(), "add_money", cost);
         destruct(blue_dragon);
         return 1; }
   }
   notify_fail("You can trade the scales with an Archeologist in Third Earth.\n");
   return 0; }
