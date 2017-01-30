#include "/players/khrell/define.h"
#include <ansi.h>
inherit "obj/weapon.c";

reset(arg) {
   ::reset(arg);
   if (arg) return;
   
   set_name(BRED+BLK+"Fellblade"+NORM);
   set_alias("blade");
   set_type("sword");
   set_short(BRED+BLK+"Fellblade"+NORM);
   set_long(
"   This is the infamous weapon known as the Fellblade.  In ages past\n"+
"the skaven crafted this weapon to combat a great enemy, though who\n"+
"it was and why has been lost to the mysts of time.  It is none the\n"+
"less still a deadly weapon.  Harsh runes seem to writhe and scrape\n"+
"along the weapons length as if begging for a release from some kind\n"+
"of eternal torment.\n"); 
   set_read("Kill-kill - Maim-slay!  Horned Rat's RAGE!\n");
   set_class(20);
   set_weight(5);
   set_value(10000);
   set_hit_func(this_object());
}

weapon_hit(attacker){
   
   int W;
   W = random(12);
   if(W > 6)  {
      
      say("You feel a moment of bloodlust pass through your mind.\n");
      write("The "+BRED+HIK+"Fellblade"+NORM+" fills your mind with thoughts of "+HIR+"slaughter"+NORM+"!\n");
      return 2;
      
   }
   return;
}
