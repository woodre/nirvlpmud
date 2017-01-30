#define tpn this_player()->query_name()  /* player name  */
#include "/players/dreamspeakr/closed/ansi.h"
inherit "/obj/treasure";
int i;

reset(arg){
if (arg) return;
    set_id("perfleche");
    set_short(HIM+"A Shaman's Perfleche"+NORM);
    set_long("This perfleche, made from dried rawhide, was used \n"+
              "to hold the shaman's magic.  Filled with herbs, \n"+
              "twigs, and bone splinters,  he used its contents \n"+
              "to perform many rituals and healings.  You might \n"+
              "want to 'potlach' it or you may find that it has \n"+
              "some medicinal value if you were to 'use' it. \n");

    set_value(50);
    set_weight(1);
}

init(){
    add_action("use","use");
    add_action("potlach","potlach");
}

set_money(int a){ i = a; }
potlach(string str){
  if(!str || str != "perfleche"){
    notify_fail("What would you like to potlach?\n");
    return 0;
  }

  i = (3800 + random(200));
    write("You bargain with the Gods of the Anasazi.  They seem very pleased \n"+
      "Suddenly "+i+" coins fall from the heavens into your pockets.\n");
    this_player()->add_money(i);
    destruct(this_object());
    return 1;
}

use(str) {
  if(!str) { write("Use what?\n"); return 1; }
  if(str == "perfleche" || str == "perfleche") {
     write("You open the bag, reaching in carefully and pull out the contents.  \n"+
           "Suddenly the room becomes filled with a "+MAG+"dark"+NORM+HIM+" healing mist"+NORM+".   As \n"+
           "the mist fades you realize that the perfleche has disappeared and \n"+
           "your wounds have been bound by the spirits.\n");
     say(tpn+" opens the perfleche, suddenly the room is filled with a dark mist.\n");
     call_other(this_player(),"heal_self",50);
     destruct(this_object());
     return 1; 
   }
}