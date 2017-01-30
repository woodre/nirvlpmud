#include "/players/puppy/define.h"
inherit "obj/weapon.c";

reset(arg) {
   ::reset(arg);
   if (arg) return;
   
   set_name("staff");
   set_alias("oak staff");
   set_type("club");
   set_short("An oak staff");
   set_long(
      "An Oak Staff about five apples high that has been handed down\n"+
      "through the Smurf line for the last 900 years.  It doesn't\n"+
      "look like much, but just holding it gives you the feeling of\n"+ 
      "great power.\n");
   set_class(11);
   set_weight(1);
   set_value(150);
   set_hit_func(this_object());
}

weapon_hit(attacker){
   int W;
   W = random(9);
   if(W < 3)  {
      
      say(this_player()->query_name()+ "slams the Staff against his enemy.\n");
      write("You thrust the Oak Staff into "+attacker->query_name()
         + "!\n");
      
      return 3;
   }
   return;
}
