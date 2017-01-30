#include <ansi.h>
 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("Darkstone Bril'thir");
set_type("blade");
set_alias("bril'thir");
set_short("Darkstone Bril'thir");
set_long("A long curved blade with a wicked hook, the Bril'thir is wielded\n"+
         "buy a short hilt that has a large spike protruding from it.\n"+
         "As intimidating as it is deadly.\n");
set_class(18);
set_weight(2);
set_value(800+random(400));
}
