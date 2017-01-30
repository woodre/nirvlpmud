#include "/players/jaraxle/define.h"
inherit "obj/treasure";

int value1;
int value2;

id(str) { return str == "tenticle" || str == "champion tenticle"; }
reset(arg) {
   if(arg) return;
   set_short(BLK+BOLD+"A tenticle"+NORM);
   set_long("  A "+BLK+BOLD+"leathery tenticle"+NORM+" about four feet in length.  It has a\n"+
      "solid "+HIW+"steel tip"+NORM+", which has been stained with "+HIR+"blood"+NORM+".  It can\n"+
      "be traded in for coins.\n");
   set_weight(1);
}
init() 
{
   add_action("give_me_coins","trade");
   value1 = (1000+random(300));
   value2 = (850+random(650));
}
give_me_coins(str) 
{
   if(id(str)) 
      {
      if(present("ahna",environment(this_player()))) 
         {
         write("  Ahna carefully looks over the tenticle, and after weighing\n"+
            "it in his hands, offers to trade it for "+HIW+""+value1+" coins"+NORM+".  As\n"+ 
            "you accept, he flops the tenticle onto the counter and a sly\n"+ 
            "smile emerges from his pursed lips.  \"Please visit me again\n"+ 
            "should you come across anymore tenticles, this one will make many\n"+
            "fine items to sell in my store.\"\n");
         this_player()->add_money(value1);
         this_player()->add_weight(-1);
         destruct(this_object());
         return 1;
      }
   }
   if(id(str)) 
      {
      if(present("gavin",environment(this_player()))) 
         {
         write("  As Gavin takes a careful look at the tenticle, he begins\n"+
            "to tap his fingers lightly on the countertop.  Reaching\n"+ 
            "into his pocket, he says, \"I believe I can find a buyer\n"+ 
            "for this,\" and offers you "+HIW+""+value2+""+NORM+" in a trade.  As he\n"+
            "hands you the money, he winks.  \"Please bring me any more\n"+
            "odd items you may find.\"\n");
         this_player()->add_money(value2);
         this_player()->add_weight(-1);
         destruct(this_object());
         return 1;
      }
   }
   notify_fail("Trade what?\n");
}
