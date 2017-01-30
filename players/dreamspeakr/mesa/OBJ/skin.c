#include "/players/dreamspeakr/closed/ansi.h"
inherit "/obj/treasure";

int i;

reset(arg){
  if (arg) return;
     set_id("skin");
     set_short(HIG+"A skin from a chameleon lizard"+NORM);
     set_long("This skin once belonged to a chameleon lizard near \n"+
              "the Mesa Verde.  You might want to 'potlach' it, \n"+
              "maybe you will get a decent price for it.\n");
     set_value(50);
     set_weight(1);
}

init(){

     add_action("potlach","potlach");
}

set_money(int a){ i = a; }

potlach(string str){
   if(!str || str != "skin"){
      notify_fail("What would you like to potlach?\n");
      return 0;
   }

i = (400 + random(100));
   write("You bargain with the Gods of the Anasazi.  They seem favorable. \n"+
         "Suddenly "+i+" coins fall from the heavens into your pockets.\n");
   this_player()->add_money(i);
   destruct(this_object());
   return 1;
}
