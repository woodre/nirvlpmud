#include "/players/jareel/define.h"
inherit "/obj/weapon";

reset(arg){
    if(arg) return;
    ::reset(arg);
    set_alias("maul");
  set_id("maul");
    set_short("A maul");
    set_long("This maul is very simple it is basically a\n"+
                     "large hunk of wood.  The maul looks very\n"+
                     "heavy.\n");
set_class(16);
    set_weight(4);
    set_type("maul");
    set_value(2000);
    set_hit_func(this_object());
}
weapon_hit(attacker){
int i;
i = random(7);
if(i==1){
write(
         ""+TPN+" knocks some sense into you.\n");
return 3;
}
}
