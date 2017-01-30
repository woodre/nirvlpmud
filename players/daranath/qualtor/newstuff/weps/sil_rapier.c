#include <ansi.h>
 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("silver rapier");
set_type("sword");
set_alias("rapier");
set_short("Silver Rapier");
set_long("A simple silver rapier, flexible yet deadly in a fight.\n");
set_class(16);
set_weight(1);
set_value(300);
}
