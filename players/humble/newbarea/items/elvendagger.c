/*COPYRIGHT (C) VITAL CORP */
/* A HUMBLE MANIPULATION */
#include "../defs.h"
inherit "obj/weapon.c";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name(HIG+"Elven Dagger"+NORM);
    set_short(HIG+"Elven Dagger"+NORM);
    set_alias("dagger");
    set_type("knife");
    set_long(HIW+"A small sharp dagger forged from a smooth solid metal.\n"+NORM+
    HIW+"It has a short hilt wrapped in some sort of local leaf which gives it\n"+NORM+
    HIW+"an incredible grip.  The blade is magnificiently sharp with a great\n"+NORM+
    HIW+"reflective surface.  This could pose deadly in close-range combat.\n"+NORM);
    set_class(12);
    set_weight(2);
    set_value(75);
}
