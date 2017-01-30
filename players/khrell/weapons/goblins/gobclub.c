#include "/players/khrell/define.h"
#include <ansi.h>
inherit "obj/weapon.c";

reset(arg) {
   ::reset(arg);
   if (arg) return;
   
   set_name("head basher");
   set_alias("prodder");
   set_type("club");    
      set_short(HIK+"'Ead Basher da Klub"+NORM);
   set_long("A massive club of petrified wood stamped with powerful shamanistic\n\
runes and glyphs.\n");
   set_read("The runes are impossible to read\n");
   set_class(16);
   set_weight(4);
   set_value(1000);
   set_hit_func(this_object());
}

weapon_hit(attacker){
   
   int W;
   W = random(12);
   if(W > 9)  {
      
      say("The club bashes the head of it's foe.\n");
      write("The club pummels your enemy.\n");
      return 3;
      
   }
   return;
}
