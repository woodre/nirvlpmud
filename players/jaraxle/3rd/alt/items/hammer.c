#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/closed/weapon/weapon2.c";
reset(arg) {
   ::reset(arg);
   if (arg) return;
   set_name("hammer");
   set_alias("hammer");
   set_type("club"); 
   set_short("Hammer");
   set_class(12);
   set_weight(3);
   set_value(5000);
   set_hit_func(this_object());
}

