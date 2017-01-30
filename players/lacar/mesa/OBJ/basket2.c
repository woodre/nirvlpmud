#include "/players/dreamspeakr/closed/ansi.h"
inherit "/obj/treasure";

int i;

reset(arg){
  if (arg) return;
     set_id("basket");
     set_short(HIY+"An exquisite hand woven basket"+NORM);
     set_long("A exquisite basket, woven from yucca stingers \n"+
              "and turkey feathers by the Anasazi women from \n"+
              "the Mesa Verde.  You might want to 'potlach' \n"+
              "it, maybe you will get a decent price for it.\n");
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

  i = (3200 + random(300));
    write("You bargain with the Gods of the Anasazi.  They seem very pleased \n"+
          "Suddenly "+i+" coins fall from the heavens into your pockets.\n");
    this_player()->add_money(i);
    destruct(this_object());
    return 1;
}
