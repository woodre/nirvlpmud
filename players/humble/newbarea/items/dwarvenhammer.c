/*COPYRIGHT (C) VITAL CORP */
/* A HUMBLE MANIPULATION */
#include "../defs.h"
inherit "obj/weapon.c";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name(HIW+"Dwarven Hammer"+NORM);
    set_short(HIW+"Dwarven Hammer"+NORM);
    set_alias("hammer");
    set_type("mace");
    set_long(HIW+"A long hammer.  The pommel is wrapped in tight leather with a large\n"+NORM+
    HIW+"strap around the bottom so that you can keep the weapon around your wrist.\n"+NORM+
    HIW+"The head of the hammer is made of some strange concrete material that has\n"+NORM+
    HIW+"been forged with some other metals.\n"+NORM);
    set_class(13);
    set_weight(2);
    set_value(200);
}
