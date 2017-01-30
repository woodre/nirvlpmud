#include "/players/dreamspeakr/closed/ansi.h"
inherit "/obj/treasure";

int i;

reset(arg){
  if (arg) return;
     set_id("talon");
     set_short(YEL+"A bald eagle's sharp talon"+NORM);
     set_long("This sharp talon once belonged to a bald eagle near \n"+
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
  if(!str || str != "talon"){
    notify_fail("What would you like to potlach?\n");
    return 0;
  }

  i = (600 + random(100));
    write("You bargain with the Gods of the Anasazi.  They seem favorable. \n"+
          "Suddenly "+i+" coins fall from the heavens into your pockets.\n");
    this_player()->add_money(i);
    destruct(this_object());
    return 1;
}
