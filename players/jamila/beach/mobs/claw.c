#include "/players/jamila/define.h"
inherit "obj/weapon";
int i;
reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("lobster claw");
   set_alias("claw");
   set_short("A Lobster Claw");
   set_long("A large claw taken from a slain lobster.\n");
   set_class(6);
   set_weight(1);
   set_value(350);
   
   set_hit_func(this_object());
}
weapon_hit(attacker) {
   i=random(10);
   if (i>5) {
      
      say(tpn+" strikes out bravely with a large lobster claw!\n");
      write("You strike out bravely with your large lobster claw.\n");
      return 1;
   }
   return 0;
}
