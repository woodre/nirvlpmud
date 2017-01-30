#include <ansi.h>
 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("crusader blade");
    set_type("sword");
    set_alias("blade");
set_short(HIW+"Crusader Blade"+NORM);
    set_long("The crusader blade was a favored weapon during the warfare\n"+
             "that dominated the early days of Qual'tor.\n");
    set_class(18);
    set_weight(1);
    set_value(1000);
}
