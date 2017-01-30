#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/closed/weapon/weapon2.c";
reset(arg) {
   ::reset(arg);
   if (arg) return;
   set_name("gnarled staff");
   set_alias("staff");
   set_type("club"); 
   set_short(BLK+BOLD+"Gnarled Staff"+NORM);
   set_class(12);
   set_weight(2);
   set_value(5000);
   add_special_fun("/players/jaraxle/closed/weapon/powers/lion.c");
   add_special_fun("/players/jaraxle/closed/weapon/powers/serpent.c");
   set_hit_func(this_object());
}

