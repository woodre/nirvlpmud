#include <ansi.h>
 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("Salamander Trident");
set_alias("trident");
set_type("polearm");
set_short(HIR+"Salamander Trident"+NORM);
set_long("Extremly hot to the touch and very sharp, the Salamander Trident is the\n"+
         "primary weapon of the salamander race.\n");
set_class(18);
set_weight(2);
set_value(1750);
}
