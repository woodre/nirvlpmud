#include "/players/jareel/define.h"
inherit "/obj/weapon";

reset(arg){
    if(arg) return;
    ::reset(arg);
    set_alias("spear");
  set_id("spear");
    set_short("A spear");
    set_long("This spear is very simple it is has a long\n"+
                     "wooden shaft and a metal tip.  The spear\n"+
                     "looks very pointy.\n");
set_class(16);
    set_weight(2);
    set_type("spear");
    set_value(2000);
    set_hit_func(this_object());
}
weapon_hit(attacker){
int i;
i = random(7);
if(i==1){
write(
         ""+TPN+" jabs the spear forward.\n");
return 3;
}
}
