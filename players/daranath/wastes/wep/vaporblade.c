#include <ansi.h>
 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("Vapor Blade");
set_alias("blade");
set_short(HIB+"Vapor Blade"+NORM);
set_long("A tiny version of the normal longsword, the Vapor blade has an extremly\n"+
         "well worked hilt, raising the value of the weapon.\n");
set_class(16);
set_weight(1);
set_value(1500);
}
