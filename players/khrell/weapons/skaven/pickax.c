#include "/players/khrell/define.h"
#include <ansi.h>
inherit "obj/weapon.c";

reset(arg) {
   ::reset(arg);
   if (arg) return;
   
   set_name("mining pickaxe");
   set_alias("pickaxe");
   set_type("axe");    /* sword/knife/club/axe/bow/polearm   */
   set_short("A mining pickaxe");
   set_long("This is a well used pickax, commonly used in mining.\n");
   set_class(15);
   set_weight(3);
   set_value(500);
   set_hit_func(this_object());
}

weapon_hit(attacker){
   
   int W;
   W = random(50);
   if(W > 30)  {
      
      say("The pickaxe strikes deep\n");
      write("Your pickaxe strike deep into your foe\n");
      return 5;
      
   }
   return;
}
