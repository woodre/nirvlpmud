#include "/players/khrell/define.h"
#include <ansi.h>
inherit "obj/weapon.c";

reset(arg) {
   ::reset(arg);
   if (arg) return;
   
   set_name("gobstaff");
   set_alias("staff");
   set_type("staff");    
      set_short(HIK+"The Staff of the High Shaman"+NORM);
   set_long("The carved legbone of a giant and enchanted by\n\
shaman magics and inscribed with powerful goblin\n\
runes and sigils.  It pulses with life.         \n");
   set_read("The runes speak of the ability to bonk heads well\n");
   set_class(16);
   set_weight(2);
   set_value(1000);
   set_hit_func(this_object());
}

weapon_hit(attacker){
   
   int W;
   W = random(12);
   if(W > 9)  {
      
      say("The staff hits with a sickening crunch.\n");
      write("Your staff "+HIR+" S M A C K S "+NORM+" your foe! \n");
      return 2;
      
   }
   return;
}
