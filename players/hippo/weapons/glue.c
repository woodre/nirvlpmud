#include "/players/hippo/bs.h"  /* Removed trailing ; - Rumplemintz */
inherit "obj/weapon.c";
int w;
int v;
reset(arg) {
   ::reset();
   if (arg) return;
   set_name("glue");
   set_short("a strong, 1 second glue");
   set_long("This is a glue that could make the opponent's arms"+BS+
      "stick together, so you can hurt him an extra time before"+BS+
      "he can hurt you... this is something you must like... "+BS);
   set_class(18);
   set_weight(3);
   set_value(4000);
   set_hit_func(this_object());
}
weapon_hit(attacker){
   w=random(3);
   if (w>1) {
      say("You see some glue, burning the skin of that creature."+BS);
      write("Your glue has made the arms of that awfull creature stick together"+BS+
         "You hit that ugly creature very hard! ==> EXTRA HIT!!!"+BS);
      return 3;
   }
   v=random(10);
   if(v>7) {
      say("Wow.. who is hurting that ugly creature that much?"+BS+
         
         "You think it's the one, fighting with that nice glue..."+BS);
      write("And you hit him another time..."+BS+
         "...and another time! << TSJAKKA >> !!!"+BS);
      return 6;
   }
}
