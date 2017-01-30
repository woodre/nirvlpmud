#include "/players/jamila/define.h"
inherit "obj/weapon";
int i;
reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("kicker");
   set_alias("sword");
   set_short("Ass kicker");
   set_long("This large sword fucking kicks your ass!\n");
   set_class(6);
   set_weight(1);
   set_value(350);
   
   set_hit_func(this_object());
}
weapon_hit(attacker) {
   i=random(10);
   if (i>5) {
      
      say(tpn+" hits hard with this ass kicker!\n");
      write("You hit hard with your ass kicker!\n");
      return 1;
   }
   return 0;
}
