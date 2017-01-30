/*COPYRIGHT (C) VITAL CORP */
/* A HUMBLE MANIPULATION */
#include "../defs.h"
inherit "obj/armor";

reset(arg) {
    if(!arg);
   ::reset(arg);
    set_name(RED+"Dwarven Chainmail"+NORM);
    set_alias("chainmail");
    set_short(RED+"Dwarven Chainmail"+NORM);
   set_long("Blood stained Dwarven Chainmail, it's metal has held throughout\n"+
   "the times.  It's very strong but unfortunately somewhat heavy.\n");
   set_ac(3);
    set_type("armor");
    set_weight(4);
    set_value(200);
}

