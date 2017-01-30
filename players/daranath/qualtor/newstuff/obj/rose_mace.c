#include <ansi.h>
 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("black rose mace");
    set_type("mace");
    set_alias("rose mace");
    set_short(WHT+"Mace"+NORM+" of the "+BOLD+BLK+"Black"+NORM+RED+" Rose"+NORM);
    set_long("An extremely well made mace, the head of the weapon is\n"+
             "inscribed with a black rose winding around it.\n");
    set_class(18);
    set_weight(1);
    set_value(875);
}
