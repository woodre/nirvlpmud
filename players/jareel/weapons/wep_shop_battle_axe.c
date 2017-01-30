#include "/players/jareel/define.h"
inherit "/obj/weapon";

reset(arg){
    if(arg) return;
    ::reset(arg);
    set_alias("axe");
  set_id("battle axe");
    set_short("A battle axe");
    set_long("This battle axe is very basic in design.  It\n"+
                     "is very well balenced.  The axe looks like it\n"+
                      "would hurt a lot if you were hit with it.\n");
    set_class(17);
    set_weight(2);
    set_type("axe");
    set_value(1200);
    set_hit_func(this_object());
}
weapon_hit(attacker){
int i;
i = random(3);
if(i==1){
write(
         ""+TPN+" chops with the battle axe.\n");
return 4;
}
}
