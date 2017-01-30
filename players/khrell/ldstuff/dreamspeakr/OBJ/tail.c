#include "/players/dreamspeakr/closed/ansi.h"
inherit "/obj/treasure";
int i;

reset(arg){
if (arg) return;
    set_id("stinger");
    set_short(RED+"A deadly scorpions stinger"+NORM);
    set_long("This stinger, once attached to a deadly scorpion \n"+
             "from the Mesa Verde region.  You might want to \n"+
             "'potlach' it, maybe you will get a decent price \n"+
             "for it.\n");
    set_value(50);
    set_weight(1);
}

init(){
     add_action("potlach","potlach");
}

set_money(int a){ i = a; }
potlach(string str){
  if(!str || str != "stinger"){
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
