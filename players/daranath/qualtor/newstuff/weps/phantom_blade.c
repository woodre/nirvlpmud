#include <ansi.h>
 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("Phantom Blade");
set_alias("blade");
set_type("sword");
set_short(BLK+BOLD+"Phantom Blade"+NORM);
set_long("A hilt made from pure silver, a blade made from translucent steel\n"+
         "can be seen when you wield this weapon, giving it the nickname\n"+
         "of the Phantom Blade.\n");
set_class(18);
set_weight(1);
set_value(3750);
}
