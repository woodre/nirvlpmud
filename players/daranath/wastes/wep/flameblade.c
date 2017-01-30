#include <ansi.h>
 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("Flame Blade");
set_alias("blade");
set_short(HIR+"Blade of Flame"+NORM);
set_long("A small shortsword, the "+HIR+"Blade of Flame"+NORM+" is warm to the touch\n"+
         "when you wield it. Transparent flames run along its wide blade.\n");
set_class(16);
set_weight(1);
set_value(1500);
}
