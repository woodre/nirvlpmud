#include <ansi.h>
 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("Flame Dagger");
set_alias("dagger");
set_short(HIR+"Dagger of Flame"+NORM);
set_long("A very small dagger, the "+HIR+"Dagger of Flame"+NORM+" is warm to the touch\n"+
         "when you wield it. Transparent flames run along its blade.\n");
set_class(14);
set_weight(1);
set_value(1200);
}
