#include "/players/tristian/lib/goblin_define.h"
inherit "/obj/weapon.c";

void reset(int arg) { 

    ::reset(arg);
     if(arg) return;
    set_name("sword");
    set_short("A gleeming short sword");
    set_long("This gleeming sword with a keen edge. Nothing monumental,\n"+
             "but this sword would cut you if you were not careful.\n");
    set_type("sword");
    set_class(15);
    set_weight(3);
    set_value(90);

}
