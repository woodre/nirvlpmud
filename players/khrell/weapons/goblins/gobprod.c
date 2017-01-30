#include "/players/khrell/define.h"
inherit "obj/weapon.c";

reset(arg) {
   ::reset(arg);
   if (arg) return;
   
   set_name("goblin-prodder");
   set_alias("prodder");
   set_type("spear");    
      set_short("A Goblin-prodder");
   set_long("A very large three bladed fork used by goblins to motivate things.\n");
   set_class(13);
   set_weight(4);
   set_value(100);
   set_hit_func(this_object());
}

weapon_hit(attacker){
   
   int W;
   W = random(12);
   if(W > 9)  {
      
      say("The prodder pokes it's foe.\n");
      write("Your prodder jabs your enemy.\n");
      return 5;
      
   }
   return;
}
