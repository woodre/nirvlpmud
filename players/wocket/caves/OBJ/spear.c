#include "/players/wocket/closed/ansi.h"
inherit "/obj/weapon";

reset(arg){
set_name("spear");
set_short("A sturdy spear");
set_long("A sturdy wooden spear.  It has a metal spike attacked to a wooden stick\n"+
         "with thick vines.\n");
set_class(16);
set_type("spear");
set_weight(2);
set_value(1000);
set_hit_func(this_object());
}

weapon_hit(){
int W;
W = random(5);
if(W == 1){
    write("The spear finds it's mark and strikes deeply.\n");
    return 2;
}
}