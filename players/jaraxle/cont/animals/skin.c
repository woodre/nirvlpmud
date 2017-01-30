#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_alias("animal skin");
   set_short("An animal skin");
   set_weight(1);
   set_value(1);
}
   id(str){ return str == "fur" || str == "skin"; }
long(){ write("An animal skin that can be bartered with a Furrier.\n"); }
init(){
   ::init();
   
   add_action("cash","barter");
   
}

cash(arg){      
   int cost, skin;
   skin = present("skin",environment(TO));
   cost = skin->query_value();
   if(id(arg)){
      if(present("jeweller",environment(TP))){
         write("The Jeweller gives you "+HIY+""+cost+""+NORM+" coins for the fur.\n");
         call_other(this_player(), "add_money", cost);
         destruct(skin);
         return 1; }
   }
   notify_fail("You can only barter the skin at a furrier.\n"); return 0; }

