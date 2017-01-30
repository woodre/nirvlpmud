#include "/players/jaraxle/define.h"
inherit "/obj/treasure.c";

reset(arg){
   if(arg) return;
   set_alias("full heal");
   set_short(HIY+"Lightning"+NORM+" in a Bottle");
   set_long("A small flask with a thick, clear liquid swimming\n"+
      "around inside.  Swirls of gold sparkle through\n"+
      "the liquid, ignighting a bright light within the flask.\n");
   set_value(17000);
   set_weight(1);
}
id(str){ return str == "potion" || str == "bottle" || str == "lightning in a bottle" || str == "lightning"; }

init(){
   add_action("drink","drink");
}

drink(string str){
   if(!str) return (notify_fail("Drink what?\n"), 0);
   if(str == "potion" || str == "full heal" || str == "lightning"){
      write("You carefully lift the flask to your mouth and\ndrink the liquid.  Shocks travel through your\nbody jolting your life and refreshing your soul.\n");
      this_player()->heal_self(1000);
      say(this_player()->query_name()+" drinks a potion.\n");
      call_other(this_player(),"drink_alcohol",-1000);
      call_other(this_player(),"drink_soft",-1000);
      call_other(this_player(),"eat_food",-1000);
      destruct(this_object());
      this_player()->recalc_carry();
      return 1;
   }
   notify_fail("What would you like to drink?\n"); return 0; }

query_save_flag() { return 1; }
