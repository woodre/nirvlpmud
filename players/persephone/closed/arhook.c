inherit "obj/weapon";
#include "/players/persephone/rooms.h"
reset(arg){
 ::reset();
  if(arg) return;
   set_name("hook");
   set_alias("jabber");
   set_short("A Pirate's Hook");
   set_long("This is a hook like that worn by captain hook it seems\n" +
            "to have a mystical glowing sheen about it and is remarkably\n" +
            "light.\n\n");
   set_class(16);
   set_save_flag(0);
   set_weight(1);
   set_value (20000);
   set_hit_func(TOB);
}
weapon_hit(attacker){
if(attacker->id("jeny")) {
     say(CAPTPLNM + " violently swings the hook at their foe\n");
     write("You pierce your foe with the hook causing a large gouge\n");
     attacker->wibble_jeny(random(200)-700);
     return 1;
   }
   return 1;
}
