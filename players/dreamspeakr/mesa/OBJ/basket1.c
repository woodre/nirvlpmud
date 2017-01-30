#include "/players/dreamspeakr/closed/ansi.h"
inherit "/obj/treasure";

int i;
reset(arg){
  if (arg) return;
     set_id("basket");
     set_short(HIY+"A beautiful hand woven basket"+NORM);
     set_long("A beautiful basket, woven from yucca stingers \n"+
              "by the Anasazi women from the Mesa Verde.  You \n"+
              "might want to 'potlach' it, maybe you will get \n"+
              "a decent price for it.\n");
     set_value(50);
     set_weight(1);
}

  init(){
     add_action("potlach","potlach");
  }

     set_money(int a){ i = a; }

     potlach(string str){
       if(!str || str != "basket"){
         notify_fail("What would you like to potlach?\n");
         return 0;
   }

     i = (350 + random(100));
       write("You bargain with the Gods of the Anasazi.  They seem favorable. \n"+
             "Suddenly "+i+" coins fall from the heavens into your pockets.\n");
       this_player()->add_money(i);
       destruct(this_object());
       return 1;
}
