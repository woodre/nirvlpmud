/*COPYRIGHT (C) VITAL CORP */
/* A HUMBLE MANIPULATION */
#include "../defs.h"
inherit "obj/armor";

reset(arg) {
   if(arg) return;
   ::reset(arg);
    set_name(HIB+"Wizard's Cap"+NORM);
    set_short(HIB+"Wizard's Cap"+NORM);
    set_alias("cap");
    set_long(HIW+"A very tall thick hat made from fine linen.  It resembles that of a cone\n"+NORM+
    HIW+"but seems to feel incredibly protective once worn.  It seems to\n"+NORM+
    HIW+"fit very nicely and is somewhat fashionable.\n"+NORM);
   set_ac(1);
    set_type("helmet");
   set_weight(1);
    set_value(230);
}

