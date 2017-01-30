#include "/players/jareel/define.h"
inherit "/obj/weapon";

reset(arg){
    if(arg) return;
    ::reset(arg);
    set_alias("short");
  set_id("short sword");
    set_short("A short sword");
    set_long("This short sword is very basic in design.  It\n"+
                     "is about three feet long and looks like it is\n"+
                      "really only good to be a pig sticker.\n");
    set_class(15);
    set_weight(2);
    set_type("sword");
    set_value(100);
    set_hit_func(this_object());
}
weapon_hit(attacker){
int i;
i = random(40);
if(i==1){
write(
         ""+TPN+" pokes with the short sword.\n");
return 3;
}
}
