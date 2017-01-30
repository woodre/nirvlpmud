#include "/players/jaraxle/define.h"
inherit "obj/weapon.c";
string name;
reset(arg) {
   ::reset(arg);
   if (arg) return;
   set_name("mercenary_weap");
   set_alias("bow");
   set_type("bow"); 
   set_short("Maiden's Bow (wielded)");
   set_long("A short bow.\n");
   set_class(14);
   set_weight(2);
   set_value(0);
   set_hit_func(this_object());
   message_hit=({ "shoots","with an arrow","hits","with an arrow","fires an arrow into","","drives an arrow into","","stabs","with an arrow","hits","with a screaming arrow","plunges an arrow into","" });
}
weapon_hit(attacker){
}

drop(){ destruct(this_object()); return 1; }
