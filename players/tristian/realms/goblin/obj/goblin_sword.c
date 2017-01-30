#include "/players/tristian/lib/goblin_define.h"
inherit "/obj/weapon.c";

void reset(int arg) { 

    ::reset(arg);
     if(arg) return;
    set_name("sword");
    set_short("A rusty short sword");
    set_long("This sword has seen better days. Rust adorns its blade\n"+
             "and there are a few nicks along the edge. It is still\n"+
             "serviceable however.\n");
    set_type("sword");
    set_class(13);
    set_weight(2);
    set_value(30);

}
