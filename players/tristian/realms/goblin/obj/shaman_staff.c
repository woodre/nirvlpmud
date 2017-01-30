#include "/players/tristian/lib/goblin_define.h"
inherit "/obj/weapon.c";

void reset(int arg) { 

    ::reset(arg);
     if(arg) return;
    set_name("staff");
    set_short("A short gnarled staff");
    set_long("A short staff of oak, it has been well worn from\n"+
             "being clutched by the goblin shaman.\n");
    set_type("staff");
    set_class(10);
    set_weight(2);
    set_value(50);

}
