#include "/players/jareel/define.h"
inherit "/obj/weapon";

reset(arg){
    if(arg) return;
    ::reset(arg);
    set_alias("bastard");
  set_id("bastard sword");
    set_short("A bastard sword");
    set_long("This bastard sword is very basic in design.  It\n"+
                     "is very well balanced.  The sword looks like it\n"+
                      "would hurt a lot if you were hit with it.\n");
    set_class(17);
    set_weight(2);
    set_type("sword");
    set_value(100);
    set_hit_func(this_object());
}
weapon_hit(attacker){
int i;
i = random(3);
if(i==1){
write(
         ""+TPN+" slashes with the bastard sword.\n");
return 4;
}
}
