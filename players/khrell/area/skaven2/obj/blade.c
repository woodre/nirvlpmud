#include "/players/khrell/define.h"
#include <ansi.h>
inherit "obj/weapon.c";

reset(arg) {
   ::reset(arg);
   if (arg) return;
   
   set_name("sword");
   set_alias("blade");
   set_type("sword");    /* sword/knife/club/axe/bow/polearm   */
      set_short("A nasty blade");
   set_long("This is a description of a sword.\n");
   set_read("This blade was forged by Sengard.\n");
   set_class(16);
   set_weight(2);
   set_value(500);
   set_hit_func(this_object());
}

weapon_hit(attacker){
   
   int W;
   W = random(12);
   if(W > 9)  {
      
      say("This is the message to the room\n");
      write("This is the message that goes to the person with the weapon\n");
      return 5;
      
   }
   return;
}
