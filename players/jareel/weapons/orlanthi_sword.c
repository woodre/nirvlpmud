#include "/players/jareel/define.h"
inherit "/obj/weapon";

reset(arg){
    if(arg) return;
    ::reset(arg);
    set_alias("bastard");
    set_id("bastard sword");
    set_short("A bastard sword");
    set_long("This bastard sword is very basic in design.  It\n"+
                     "is very well balenced.  The sword looks like it\n"+
                      "would hurt a lot if you were hit with it.\n");
    set_class(16);
    set_weight(2);
    set_type("sword");
    set_value(1000);
    set_hit_func(this_object());
}
