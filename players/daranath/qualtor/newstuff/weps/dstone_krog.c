#include <ansi.h>
 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("Darkstone Krog");
set_type("club");
set_alias("krog");
set_short("Darkstone Krog");
set_long("A massive club, the Krog is stained with blood and little bits of\n"+
         "flesh that remain within its wicked spikes.\n");
set_class(16);
set_weight(2);
set_value(300+random(200));
}
