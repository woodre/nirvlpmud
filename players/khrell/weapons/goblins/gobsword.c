#include "/players/khrell/define.h"
inherit "obj/weapon.c";

reset(arg) {
   ::reset(arg);
   if (arg) return;
   
   set_name("sword");
   set_alias("sword");
   set_type("sword");   
      set_short("A goblin sword");
   set_long("This sword has seen better days, it is now notched and quite well used.\n");
   set_read("This sword is notched and quite battered looking.\n");
   set_class(14);
   set_weight(2);
   set_value(125);
   set_hit_func(this_object());
}

weapon_hit(attacker){
   
   int W;
   W = random(12);
   if(W > 9)  {
      
      say("The sword bluntly hacks at it's foe.\n");
      write("Your blade hits it's foe with a slow chop.\n");
      return 5;
      
   }
   return;
}
