#include <ansi.h>
 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("Vapor Dagger");
set_alias("dagger");
set_short(HIB+"Vapor Dagger"+NORM);
set_long("A tiny version of the normal dagger, the Vapor dagger has an extremly\n"+
         "well worked hilt, raising the value of the weapon.\n");
set_class(14);
set_weight(1);
set_value(1200);
}
