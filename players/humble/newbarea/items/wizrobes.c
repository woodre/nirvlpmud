/*COPYRIGHT (C) VITAL CORP */
/* A HUMBLE MANIPULATION */
#include "../defs.h"
inherit "obj/armor";

reset(arg) {
    if(!arg);
   ::reset(arg);
    set_name(HIB+"Enchanted Robes"+NORM);
    set_short(HIB+"Enchanted Robes"+NORM);
    set_alias("robes");
    set_long(HIW+"A large elegant blue robe with hints of white surrounding\n"+NORM+
    HIW+"the outer edge of the robes.  They feel magical as you hold them, who\n"+NORM+
     HIW+"knows where they came from. They fit so comfortably, you must know\n"+NORM+
    HIW+"who tailored these fine robes.\n"+NORM);
    set_ac(3);
    set_type("armor");
    set_weight(2);
    set_value(400);
}

